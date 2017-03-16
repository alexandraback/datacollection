#!/usr/bin/env python

from sys import stdin, stderr

for T in range(int(stdin.readline())):
    N = int(stdin.readline())
    if N == 0:
        print 'Case #%d: INSOMNIA' % (T+1)
        continue

    NN = 0
    d = set()
    while len(d) < 10:
        #print T, len(d), N
        NN += N
        nn = NN
        while nn >= 10:
            d.add(nn%10)
            nn /= 10
            pass
        d.add(nn)
        pass
    print 'Case #%d:' % (T+1),
    print NN
    
