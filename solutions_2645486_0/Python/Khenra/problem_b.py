# -*- coding: utf-8 -*-
#Filename: problem_b.py

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
            print case+1
            e, r, n = map(int, input_file.readline().split())
            values = map(int, input_file.readline().split())
            
            self.max_energy = e
            
            self.output_result(self.calc_gain(e,r,n, values), case+1, output_file)
    
    
    def calc_gain(self, energy, regain, activities, values):
        
        if activities == 1:
            return energy * values[0]

        max_gain = 0
        for i in range(energy+1):
            new_energy = min(self.max_energy, energy-i+regain)
            gain = i * values[0] + self.calc_gain(new_energy, regain, activities-1, values[1:])
            
            max_gain = max(max_gain, gain)
        
        return max_gain
        
        
        
        
    
    def output_result(self, result, case_nr, output_file):
            output_file.write('Case #{}: {}\n'.format(case_nr, result))

def main(args):
    input_filename = 'sample_input.txt'
    output_filename = 'output.txt'
    
    if len(args) == 1:
        input_filename = args[0]
    elif len(args) == 2:
        input_filename = args[0]
        output_filename = args[1]
    
    ProblemB(input_filename, output_filename)


if __name__ == '__main__':
    main(sys.argv[1:])
