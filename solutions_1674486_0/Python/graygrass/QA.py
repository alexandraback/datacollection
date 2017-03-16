#! /usr/bin/env python
#coding=utf-8

#import matplotlib.pyplot as plt
from itertools import permutations as perm
from itertools import combinations as comb
from fractions import gcd


def ffind(i, inh, cc):
#    print 'ffind', i, inh
    qq = []
    for x in inh[i]:
        qq.append(x)
    while len(qq) > 0:
#        print cc
        chd = qq.pop(0)
        if chd in cc:
            return 'Yes'
        else:
            cc.add(chd)
            if chd in inh:
                for x in inh[chd]:
                    qq.append(x)
    return 'No'
    

def solve(icase, case_input):
    case_output = 'Case #%i: '%icase
    
    result = None
    
    inh = {}
    rs = []
    for i in xrange(1, len(case_input)):
        raw = [int(x) for x in case_input[i].split()]
        if raw[0] == 0:
            rs.append(i)
        else:
            dfcs = raw[1:]
            for f in dfcs:
                if f not in inh:
                    inh[f] = []
                inh[f].append(i)
    
    for i in rs:
        if i in inh:
            result = ffind(i, inh, set())
            if result == 'Yes':
                break

    case_output += '%s'%str(result)
    
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
        
#        caseLineNum = 1
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
    test_data = """4
3
2 2 3
1 3
0
3
1 2
1 3
0
5
2 2 3
1 4
1 5
1 5
0
3
2 2 3
1 3
0

"""
    use_test_data = False
    
    test_file = 'A-small-attempt0.in'
    if not use_test_data and '' != test_file:
        input_file = open(test_file)
        output_file = open(test_file + '.out', 'w')
    
    main()