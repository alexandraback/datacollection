#!/usr/bin/python
import sys, collections

data = file(sys.argv[1]).read().splitlines()

T = int(data.pop(0))

MAP = {}

MAP[('1','1')] = (1,'1')
MAP[('1','i')] = (1,'i')
MAP[('1','j')] = (1,'j')
MAP[('1','k')] = (1,'k')

MAP[('i','1')] = (1,'i')
MAP[('i','i')] = (-1,'1')
MAP[('i','j')] = (1,'k')
MAP[('i','k')] = (-1,'j')

MAP[('j','1')] = (1,'j')
MAP[('j','i')] = (-1,'k')
MAP[('j','j')] = (-1,'1')
MAP[('j','k')] = (1,'i')

MAP[('k','1')] = (1,'k')
MAP[('k','i')] = (1,'j')
MAP[('k','j')] = (-1,'i')
MAP[('k','k')] = (-1,'1')


def reduce(DATA):
    c = DATA[0]
    sign = 1
    for i in xrange(1,len(DATA)):
        (ns, c) = MAP[(c,DATA[i])]
        sign = sign * ns
    return (sign, c)

def brute(DATA,X):
    if X == 0:
        return 'NO'

    (RSIGN, RC) = reduce(DATA)
    if RSIGN == 1:
        if RC == '1':
            # '1'
            return 'NO'
        else:
            # +i,j,k
            # must be even X
            if X % 2 or X % 4 == 0:
                return 'NO'
    else:
        if RC == '1':
            # -1
            # must be odd X
            if X % 2 == 0:
                return 'NO'
        else:
            # -i,j,k
            # must be even X
            if X % 2 or X % 4 == 0:
                return 'NO'
            
    # now we know that
    # reduce(DATA*X) is (-1,'1')
    if False:
        if reduce(DATA*X) != reduce('ijk'):
            print X, reduce(DATA),reduce(DATA*X), DATA
            assert False
    
    DATA=DATA*X

    # find min i
    c = DATA[0]
    sign = 1
    MINI = 0
    if c != 'i':
        for i in xrange(1,len(DATA)):
            (ns, c) = MAP[(c,DATA[i])]
            sign = sign * ns
            if (sign,c) == (1,'i'):
                MINI = i
                break
        if MINI == 0:
            return 'NO'
    c = DATA[-1]
    MINK = len(DATA)-1
    sign = 1
    if c != 'k':
        for i in xrange(len(DATA)-2,0,-1):
            (ns, c) = MAP[(DATA[i],c)]
            sign = sign * ns
            if (sign,c) == (1,'k'):
                MINK = i
                break
        if MINK == len(DATA)-1:
            return 'NO'
    if MINK-MINI <= 0:
        return 'NO'
    return 'YES'

def fast(DATA,X):
    OLEN = len(DATA) * X
    if X == 0:
        return 'NO'

    (RSIGN, RC) = reduce(DATA)
    if RSIGN == 1:
        if RC == '1':
            # '1'
            return 'NO'
        else:
            # +i,j,k
            # must be even X
            if X % 2 or X % 4 == 0:
                return 'NO'
    else:
        if RC == '1':
            # -1
            # must be odd X
            if X % 2 == 0:
                return 'NO'
        else:
            # -i,j,k
            # must be even X
            if X % 2 or X % 4 == 0:
                return 'NO'
            
    # now we know that
    # reduce(DATA*X) is (-1,'1')
    if False:
        if reduce(DATA*X) != reduce('ijk'):
            print X, reduce(DATA),reduce(DATA*X), DATA
            assert False
    
    DATA=DATA*5

    # find min i
    c = DATA[0]
    sign = 1
    MINI = 0
    if c != 'i':
        for i in xrange(1,len(DATA)):
            (ns, c) = MAP[(c,DATA[i])]
            sign = sign * ns
            if (sign,c) == (1,'i'):
                MINI = i
                break
        if MINI == 0:
            return 'NO'
    c = DATA[-1]
    MINK = len(DATA)-1
    sign = 1
    if c != 'k':
        for i in xrange(len(DATA)-2,0,-1):
            (ns, c) = MAP[(DATA[i],c)]
            sign = sign * ns
            if (sign,c) == (1,'k'):
                MINK = i
                break
        if MINK == len(DATA)-1:
            return 'NO'

    offset = len(DATA) - MINK
    FK = OLEN - offset
    if MINI >=OLEN or FK <= 0:
        return 'NO'

    if FK-MINI <= 0:
        return 'NO'
    return 'YES'

for numcase in xrange(1,T+1):
    print 'Case #%d:' % numcase,
    (L, X) = [int(x) for x in data.pop(0).split()]
    DATA = data.pop(0)

    #    print reduce(DATA), DATA

    f = fast(DATA,X)
#    b = brute(DATA,X)
#    assert b == f

    print f



