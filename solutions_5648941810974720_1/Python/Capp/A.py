#!/usr/bin/env python

from sys import stdin, stderr

def Solve(S):
    ret = [None] * 10
    ret[0] = S.count('Z')
    ret[1] = S.count('N')
    ret[2] = S.count('W')
    ret[3] = S.count('H')
    ret[4] = S.count('U')
    ret[5] = S.count('F')
    ret[6] = S.count('X')
    ret[7] = S.count('S')
    ret[8] = S.count('G')
    ret[9] = S.count('I')
    ret[3] -= ret[8]
    ret[5] -= ret[4]
    ret[7] -= ret[6]
    ret[9] -= ret[5] + ret[6] + ret[8]
    ret[1] -= ret[7] + ret[9] * 2

    rets = ''
    for i in range(10): rets += str(i) * ret[i]

    return rets



for T in range(int(stdin.readline())):
    S = stdin.readline().strip()

    print 'Case #%d:' % (T+1),
    print Solve(S)
