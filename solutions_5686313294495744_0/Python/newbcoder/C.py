#!/usr/bin/python

import sys

def solve(firsts, lasts):
    fword = []
    lword = []
    soln = 0
    for i in range(len(firsts)):
        if firsts.count(firsts[i]) > 1 and lasts.count(lasts[i]) > 1:
            #print('{:} - {:}'.format(firsts[i], lasts[i]))
            soln += 1

    return soln

with open(sys.argv[1], 'r') as f:
    cases = int(f.readline())
    for case in range(cases):
        strings = int(f.readline())
        firsts = []
        lasts = []
        #fword = dict()
        #lword = dict()
        for string in range(strings):
            first, last = f.readline().strip().split()
            firsts.append(first)
            lasts.append(last)
           # if first in fword:
           #     fword[first] += 1
           # else:
           #     fword[first] = 1
            
            #if last in lword:
            #    lword[last] += 1
            #else:
            #    lword[last] = 1
        #ans = solve(firsts, lasts, fword, lword)
        ans = solve(firsts, lasts)
        print("Case #{:}: {:}".format(case+1, ans))


