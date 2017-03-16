# Filename: problem_b.py

import sys

class ProblemB:

    def __init__(self, input_filename, output_filename):
        
        # Open input and output files
        input_file = open(input_filename, 'r')
        output_file = open(output_filename, 'w')
        
        # Get the number of cases
        number_of_cases = int(input_file.readline())
        
        # Evaluate all cases and output the result to the output file
        for case in range(number_of_cases):
            x, y = map(int, input_file.readline().split())
            result = self.solve(x, y) 
            print case+1, result
            self.output_result(result, case + 1, output_file)
    
    def solve(self, x, y):
        # Try all paths
        paths = {(0,0):''}
        jump = 1
        while not (x,y) in paths:
            new_paths = {}
            for path in paths:
                new_paths[(path[0], path[1]+jump)] = paths[path] + 'N'
                new_paths[(path[0], path[1]-jump)] = paths[path] + 'S'
                new_paths[(path[0]+jump, path[1])] = paths[path] + 'E'
                new_paths[(path[0]-jump, path[1])] = paths[path] + 'W'
            paths = new_paths
            jump += 1
                
            if jump > 50:
                print 'ERROR'
                break
        
        return paths[(x,y)]

    
    def output_result(self, result, case_nr, output_file):
            output_file.write('Case #{}: {}\n'.format(case_nr, result))

def main(args):
    input_filename = 'B-small-attempt0.in'#'sample_input.txt'
    output_filename = 'output.txt'
    
    if len(args) == 1:
        input_filename = args[0]
    elif len(args) == 2:
        input_filename = args[0]
        output_filename = args[1]
    
    ProblemB(input_filename, output_filename)


if __name__ == '__main__':
    main(sys.argv[1:])
