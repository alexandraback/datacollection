#! /usr/bin/env python
#coding=utf-8

#import matplotlib.pyplot as plt
from itertools import permutations as perm
from itertools import combinations as comb
from fractions import gcd


def solve(icase, case_input):
    case_output = 'Case #%i: '%icase
    
    result = "Too Bad"
    
    lv = []
    for line in case_input[1:]:
        lv.append([int(x) for x in line.split()])

#    print lv

    tt = len(lv)
    
    s1 = []
    s2 = []
    
#    print(len(lv) * 2)
    
    for i in xrange(len(lv)):
        t = (i, lv[i][0], lv[i][1])
        s1.append(t)
        s2.append(t)
    
    s1.sort(lambda x, y: cmp(x[1], y[1]))
    s2.sort(lambda x, y: cmp(x[2], y[2]))
    
#    print s1
#    print s2

    cnt = 0
    cs = 0
    while len(s2) > 0:
        if s2[0][2] <= cs:
            if s2[0] in s1:
                cs += 2
                s1.remove(s2[0])
                cnt += 1
            else:
                cs += 1
            s2.pop(0)
        else:
            if len(s1) == 0:
                break
            elif s1[0][1] <= cs:
                cs += 1
                s1.pop(0)
            else:
                break

    if len(s2) > 0:
        result = "Too Bad"
    else:
        result = "%d"%(tt+tt-cnt)
    case_output += '%s'%result
    
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
        
        caseLineNum = 1
        caseLineNum = 1 + int(data[iLine].split()[0])
        
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
    test_data = """5
1
0 2
2
0 1
0 2
3
2 2
0 0
4 4
1
1 1
5
0 5
0 1
1 1
4 7
5 6
"""
    use_test_data = False
    
    test_file = 'B-small-attempt1.in'
    if not use_test_data and '' != test_file:
        input_file = open(test_file)
        output_file = open(test_file + '.out', 'w')
    
    main()