#!/usr/bin/python
# -*- coding: utf-8 -*-

T = int(raw_input().strip())

for t in xrange(0, T):
    N = int(raw_input().strip())
    if N:
        shown = {str(k): False for k in range(10)}
        M = 0
        while not all(shown[str(k)] for k in range(10)):
            M += N
            for s in set(str(M)):
                shown[s] = True
        answer = M
    else:
        answer = "INSOMNIA"

    print "Case #%i: %s\n" % (t+1, answer)


