#!/usr/local/bin/python2.7

import sys
import math

def readint(): return int(raw_input())
def readarray(f): return map(f, raw_input().split())

_T = readint()
for _t in range(_T):

    K, C, S = readarray(int)

    if S*C < K:
        res = ['IMPOSSIBLE']
    else:
        C = min(K, C)
        S = int(math.ceil(float(K)/float(C)))
        helper = range(S*C)
        res = []
        for s in range(S):
            num = 1
            for c in range(C):
                num += (helper[C*s + c] % K)*(K**(C - c - 1))
            res.append(str(num))


    print ('Case #%i: ' % (_t + 1)) + ' '.join(res)
    sys.stdout.flush()
