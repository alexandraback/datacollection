# -*- coding: utf-8 -*-
#Filename: problem_a.py

import sys
import math

class ProblemA:

    def __init__(self, input_filename, output_filename):
        
        # Open input and output files
        input_file = open(input_filename, 'r')
        output_file = open(output_filename, 'w')
        
        # Get the number of cases
        number_of_cases = int(input_file.readline())
        
        # Evaluate all cases and output the result to the output file
        for case in range(number_of_cases):
            print case+1
            radius, t = map(int, input_file.readline().split())
            
            
            self.output_result(self.calc_circles(radius, t), case+1, output_file)
    
    def calc_circles(self, radius, t):
        
        first_ring = (radius+1)**2 - radius**2
        t -= first_ring
        
        ring = 1
        while t > 0:
            ring += 1
            
            req_paint = ((radius + ring + ring-1)**2 - (radius + ring + ring-2)**2)
            
            t -= req_paint
            if t<0:
                ring -= 1
        return ring
        
    
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
    
    ProblemA(input_filename, output_filename)


if __name__ == '__main__':
    main(sys.argv[1:])
