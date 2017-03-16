#!/usr/bin/python
# -*- coding: utf-8 -*-

T = int(raw_input().strip())

for t in xrange(0, T):
    K, C, S = tuple(map(int, raw_input().strip().split()))
    if S == K:
        answer = " ".join(str(1+i) for i in range(S))
    elif C == 1:
        answer = "IMPOSSIBLE"
    elif S == K-1:
        answer = " ".join(str(2+i) for i in range(S))
    else:
        answer = "IMPOSSIBLE"

    print "Case #%i: %s\n" % (t+1, answer)


