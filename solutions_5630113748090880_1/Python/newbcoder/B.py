#!/usr/bin/python

import sys

def solve(solds):
    #print(solds)
    hist = dict()
    for i in range(len(solds)):
        for j in range(len(solds[i])):
            if solds[i][j] in hist:
                hist[solds[i][j]] += 1
            else:
                hist[solds[i][j]] = 1

    out = []
    for k in hist.keys():
        if hist[k] % 2 == 1:
            out.append(k)

        #print('{:} -> {:}'.format(k, hist[k]))
    out.sort()
    
    return ' '.join(map(str,out))

with open(sys.argv[1], 'r') as f:
    cases = int(f.readline())
    for case in range(cases):
        N = int(f.readline())
        lls = []
        for i in range(N*2-1):
            solds = list(map(int, f.readline().split()))
            lls.append(solds)

        ans = solve(lls)
        print("Case #{:}: {:}".format(case+1, ans))


