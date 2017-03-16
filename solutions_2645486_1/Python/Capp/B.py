#!/usr/bin/env python

from sys import stdin

def value(Emax, Est, Een, R, v):
    #print Emax, Est, Een, R, v
    N = len(v)
    v_max = max(v)
    v_index = v.index(v_max)

    ret = 0

    # prev
    st = v_index * R + Est
    if(st > Emax):
        st = Emax
        ret += value(Emax, Est, max([Emax-R, 0]), R, v[0:v_index])
        pass
    en = Een - (N - v_index - 1) * R
    if(en < 0):
        en = 0
        ret += value(Emax, min([R, Emax]), Een, R, v[v_index+1:])
        pass
    ret += v_max * (st - en)

    return ret



T = int(stdin.readline())

for t in range(T):
    print "Case #%d:" % (t+1),

    ## read
    wds = stdin.readline().split()
    E = int(wds[0])
    R = int(wds[1])
    wds = stdin.readline().split()
    v = [int(_v) for _v in wds]

    ## solve
    print value(E, E, 0, R, v)

    pass
