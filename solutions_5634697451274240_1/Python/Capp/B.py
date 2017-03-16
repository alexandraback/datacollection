#!/usr/bin/env python

from sys import stdin, stderr

for T in range(int(stdin.readline())):
    S = stdin.readline().strip()
    S += '+'
    ret = 0
    for i in range(len(S)-1):
        if S[i] != S[i+1]: ret += 1
        pass

    print 'Case #%d:' % (T+1),
    print ret
    
