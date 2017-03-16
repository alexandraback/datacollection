#!/usr/bin/env python3

# (C) 2014 Susanne Oberhauser-Hirschoff
# The MIT License applies: http://opensource.org/licenses/MIT

# Google codejam 2014

class Codejam_2014:
    def __init__(self, sep = ' '):
        self.separator = sep

    def run(self, filename):
        # open file
        self.file = open(filename)
        # read header (number of test cases)
        self.T    = int(self.file.readline())

        # iterate problems
        for number in range(1, self.T+1):
            problem = self.parse_one_problem_set()

            solution = self.solve_problem(problem)
            
            solution_str = self.str_solution(solution)
            print("Case #{number}:{separator}{solution}".format(number    = number,
                                                                separator = self.separator,
                                                                solution  = solution_str))
    def parse_one_problem_set(self): raise
    def solve_problem(self): raise
    def str_solution(self): raise
