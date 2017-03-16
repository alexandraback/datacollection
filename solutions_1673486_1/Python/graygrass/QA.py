#! /usr/bin/env python
#coding=utf-8

#import matplotlib.pyplot as plt
from itertools import permutations as perm
from itertools import combinations as comb
from fractions import gcd


def solve(icase, case_input):
    case_output = 'Case #%i: '%icase
    
    td, tt = [int(x) for x in case_input[0].split()]
    p = [float(x) for x in case_input[1].split()]
    pp = list(p)
    for i in xrange(1, len(pp)):
        pp[i] *= pp[i-1]
    
    mine = tt + 2
    for n in xrange(td+1):
        lp = pp[td-n-1]
        c = n+n+(tt-td)+1
        e = (lp*c)+((1-lp)*(c+tt+1))
        if e < mine:
            mine = e
    
    result = mine

    case_output += '%.6f'%result
    
    return case_output


def main():
    global use_test_data
    global test_data
    global input_file
    global output_file
    
    if use_test_data:
        data = [x.strip() for x in test_data.split('\n')]
    else:
        data = [x.strip() for x in input_file.readlines()]
    
    T = int(data[0])
    iLine = 1
    for icase in range(1, T + 1):
        input = []
        
        caseLineNum = 2
#        caseLineNum = 1 + int(data[iLine].split()[0])
        
        for i in range(caseLineNum):
            input.append(data[iLine])
            iLine += 1
        rslt = solve(icase, input)
        print rslt
        if not use_test_data:
            print >> output_file, rslt
    
    if not use_test_data:
        input_file.close()
        output_file.close()
    
    
if __name__ == '__main__':
    test_data = """3
2 5
0.6 0.6
1 20
1
3 4
1 0.9 0.1
"""
    use_test_data = False
    
    test_file = 'A-large.in'
    if not use_test_data and '' != test_file:
        input_file = open(test_file)
        output_file = open(test_file + '.out', 'w')
    
    main()