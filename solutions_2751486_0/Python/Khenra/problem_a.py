# Filename: problem_a.py

import sys

class ProblemA:

    def __init__(self, input_filename, output_filename):
        
        # Open input and output files
        input_file = open(input_filename, 'r')
        output_file = open(output_filename, 'w')
        
        # Get the number of cases
        number_of_cases = int(input_file.readline())
        
        # Evaluate all cases and output the result to the output file
        for case in range(number_of_cases):
            
            
            name, n = input_file.readline().split()
            result = self.solve(name, int(n)) 
            print case+1, result
            self.output_result(result, case + 1, output_file)
    
    def solve(self, name, n):
        n_value = 0
        for i in xrange(len(name)-n+1):
            for j in xrange(i+n, len(name)+1):
                substring = name[i:j]
                #print substring
                v_index = -1
                for c in range(len(substring)):
                    if substring[c] in ['a','e','i', 'o','u']:
                        v_index = c
                        continue
                    if c >= v_index + n:
                        n_value += 1
                        break
                
        return n_value
    
    def output_result(self, result, case_nr, output_file):
            output_file.write('Case #{}: {}\n'.format(case_nr, result))

def main(args):
    #input_filename = 'sample_input.txt'
    input_filename = 'A-small-attempt0.in'
    output_filename = 'output.txt'
    
    if len(args) == 1:
        input_filename = args[0]
    elif len(args) == 2:
        input_filename = args[0]
        output_filename = args[1]
    
    ProblemA(input_filename, output_filename)


if __name__ == '__main__':
    main(sys.argv[1:])
