# -*- coding: utf-8 -*-
#Filename: problem_c.py

import sys

class ProblemC:

    def __init__(self, input_filename, output_filename):
        
        # Open input and output files
        input_file = open(input_filename, 'r')
        output_file = open(output_filename, 'w')
        
        # Get the number of cases
        number_of_cases = int(input_file.readline())
        
        
        
        # Evaluate all cases and output the result to the output file
        for case in range(number_of_cases):
            
            r, n, m, k = map(int, input_file.readline().split())
            
            self.hypos = self.calc_hypotheses(n, m)
            
            guesses = []
            for i in range(r):
                print i+1
                products = (map(int, input_file.readline().split()))
                guesses.append(self.guess_numbers(n, m, products))
        
            self.output_result(guesses, case+1, output_file)
    
    
    def calc_hypotheses(self, n, m):
        
        if n == 1:
            return [[i] for i in range(2, m+1)]
        
        hypos = []
        for i in range(2, m+1):
            for h in self.calc_hypotheses(n-1, m):
                h2 = list(h)
                hypos.append(h2 + [i])
        
        return hypos
    
    def guess_numbers(self, n, m, products):

        new_hypos = list(self.hypos)

        for p in products:
            for h in list(new_hypos):
                if not self.producable(p, h):
                    new_hypos.remove(h)

        return new_hypos[0]
    
    
    def producable(self, p, h):
        
        if p == 1:
            return True
        if p in h:
            return True
        if h[0]*h[1] == p:
            return True
        if h[0]*h[2] == p:
            return True
        if h[1]*h[2] == p:
            return True
        if h[0]*h[1]*h[2] == p:
            return True

        return False
        
    
    
    def output_result(self, result, case_nr, output_file):
            output_file.write('Case #{}:\n'.format(case_nr))
            for r in result:
                output_file.write('{}\n'.format(self.list_to_string(r)))

    def list_to_string(self, string_list):
        string = ''
        for word in string_list:
            string += str(word)
        return string

def main(args):
    input_filename = 'sample_input.txt'
    output_filename = 'output.txt'
    
    if len(args) == 1:
        input_filename = args[0]
    elif len(args) == 2:
        input_filename = args[0]
        output_filename = args[1]
    
    ProblemC(input_filename, output_filename)


if __name__ == '__main__':
    main(sys.argv[1:])
