#!/usr/bin/env python

from sys import stdin
from numpy import array, log2, floor, ceil, sort
from math import factorial

def asshuku(s1):
    #print s1
    pool = s[0]
    for c in s[1:]:
        if pool[-1] == c: continue
        pool += c
        continue
        pass
    return pool


def kasanecheck(s1):
    #print s1
    pool = s[0]
    for c in s[1:]:
        if pool[-1] == c: continue
        if c in pool:
            #print "OUT"
            return False
        pool += c
        continue
        pass
    return True


T = int(stdin.readline())

for t in range(T):
    print "Case #%d:" % (t+1),

    N = int(stdin.readline())
    ss = stdin.readline().split()
    impossible = False
    ret = 1
    jiyuu = 0
    dekita = ""

    #if t != 89: continue

    #print ss
    #for s in ss: print asshuku(s)

    while not impossible and len(ss) > 0:
        check = ss[0][0]
        nows = []
        nexts = []
        for s in ss:
            if check in s:
                nows.append(s)
            else:
                nexts.append(s)
                pass
            pass
        mae = []
        ushiro = []
        naka = []
        for s in nows:
            if s[0] == check:
                if s[-1] == check:
                    naka.append(s)
                else:
                    ushiro.append(s)
                    pass
                pass
            else:
                if s[-1] == check:
                    mae.append(s)
                else:
                    impossible = True
                    pass
                pass
            pass
        if len(mae) > 1:    impossible = True
        if len(ushiro) > 1: impossible = True
        ret *= factorial(len(naka))
        ret %= 1000000007
        awase = ""
        #print "0", mae, naka, ushiro
        if len(mae) >= 1: awase += mae[0]
        for s in naka: awase += s
        if len(ushiro) >= 1: awase += ushiro[0]
        #print "1", ss, awase, "hoge"
        ss = []
        ss.append(awase)
        ss.extend(nexts)

        if len(mae) == 1: continue

        #print "2", ss
        check = ss[0][-1]
        nows = []
        nexts = []
        for s in ss:
            if check in s:
                nows.append(s)
            else:
                nexts.append(s)
                pass
            pass
        mae = []
        ushiro = []
        naka = []
        for s in nows:
            if s[0] == check:
                if s[-1] == check:
                    naka.append(s)
                else:
                    ushiro.append(s)
                    pass
                pass
            else:
                if s[-1] == check:
                    mae.append(s)
                else:
                    impossible = True
                    pass
                pass
            pass
        if len(mae) > 1:    impossible = True
        if len(ushiro) > 1: impossible = True
        ret *= factorial(len(naka))
        ret %= 1000000007
        awase = ""
        if len(mae) == 1: awase += mae[0]
        for s in naka: awase += s
        if len(ushiro) == 1: awase += ushiro[0]
        ss = []
        ss.append(awase)
        ss.extend(nexts)

        if len(ushiro) == 1: continue

        dekita += ss[0]
        jiyuu += 1
        ss = ss[1:]

        pass

    if not kasanecheck(dekita): impossible = True

    if impossible:
        print 0
    else:
        print (factorial(jiyuu) * ret) % 1000000007
        kasanecheck(dekita)
