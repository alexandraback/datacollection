#!/usr/bin/env python


from sys import stdin

T = int(stdin.readline())

for t in range(T):
    wds = stdin.readline().split()
    A = int(wds[0])
    B = int(wds[1])

    wds = stdin.readline().split()
    p = [ float(i) for i in wds ]

    ## reset
    ret = [1 + B + 1]

    ## backspace
    for a in range(A+1):
        prob = 1
        for _p in p[0:a]: prob *= _p
        ret.append(((A-a)+(B-a)+1)+(1-prob)*(B+1))
        pass

    print "Case #%d: %6f" % ((t+1), min(ret))
