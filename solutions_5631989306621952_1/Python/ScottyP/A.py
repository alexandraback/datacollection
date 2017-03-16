#!/usr/local/bin/python2.7

import sys

def readint(): return int(raw_input())
def readarray(f): return map(f, raw_input().split())

_T = readint()
for _t in range(_T):

    S = raw_input()
    res = S[0]

    for i in range(1, len(S)):
        if S[i] >= res[0]:
            res = S[i] + res
        else:
            res = res + S[i]

    print 'Case #%i:'%(_t+1), res
    sys.stdout.flush()
