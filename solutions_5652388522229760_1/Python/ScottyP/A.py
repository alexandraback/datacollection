#!/usr/local/bin/python2.7

import sys

def readint(): return int(raw_input())
def readarray(f): return map(f, raw_input().split())

_T = readint()
for _t in range(_T):

    N = readint()
    res = N
    D = set()
    count = 0
    k = 0
    while True:
        for i in str(res):
            if not (i in D):
                D.add(i)
                count += 1
        if count == 10:
            break
        res += N 
        k += 1
        if k > 2000:
            res = 'INSOMNIA'
            break



    print 'Case #%i:'%(_t+1), res
    sys.stdout.flush()
