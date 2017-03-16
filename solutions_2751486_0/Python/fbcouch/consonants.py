#!/usr/bin/pypy

import fileinput, math

vowels = "aeiou"

class Case(object):
    casenum = 0
    name = None
    n = 0
    
    solution = -1
    
    def __init__(self, casenum, name, n):
        self.casenum = casenum
        self.name = name
        self.n = n
        
    def solve(self):
        self.solution = 0
        for start in range(0, len(self.name) - self.n + 1):
            for end in range(len(self.name), start + self.n - 1, -1):
                if self.count_consonants(self.name[start:end]) >= self.n:
                    self.solution += 1
        
        return self.solution
        
    def count_consonants(self, subname):
        max_c = 0
        c = 0
        for l in subname:
            if not l in vowels:
                c += 1
            else:
                if c > max_c: 
                    max_c = c
                c = 0
        if c > max_c: 
            max_c = c
        return max_c
        
    def __str__(self):
        if self.solution == -1:
            self.solve()
            
        return "Case #%i: %i" % (self.casenum, self.solution)


def readcases(lines):
    cases = []
    firstline = True
    for line in lines:
        if firstline:
            firstline = False
            continue
            
        bounds = line.split()
        cases.append(Case(len(cases) + 1, bounds[0], int(bounds[1])))
    return cases
    
cases = []
if __name__ == "__main__":
    cases = readcases(fileinput.input())
    
    for case in cases:
        print case
