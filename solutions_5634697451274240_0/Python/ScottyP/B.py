#!/usr/local/bin/python2.7

import sys

def readint(): return int(raw_input())
def readarray(f): return map(f, raw_input().split())

_T = readint()
for _t in range(_T):

    s = raw_input().replace('\r', '').replace('\n', '')
    s += '+'
    res = 0
    last = s[0][:]
    for i in s[1:]:
        if i != last:
            res += 1
        last = i[:]

    print 'Case #%i:'%(_t+1), res
    sys.stdout.flush()
