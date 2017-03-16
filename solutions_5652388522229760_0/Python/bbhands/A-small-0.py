#!/usr/bin/python
# -*- coding: utf-8 -*-

T = int(raw_input().strip())

for t in xrange(0, T):
    N = int(raw_input().strip())
    if N:
        shown = {str(k): False for k in range(10)}
        i = 1
        while not all(shown[str(k)] for k in range(10)):
            for s in list(str(i*N)):
                shown[s] = True
            i += 1
        answer = (i-1)*N
    else:
        answer = "INSOMNIA"

    print "Case #%i: %s\n" % (t+1, answer)


