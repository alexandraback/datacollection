#!/usr/bin/python
import sys, collections
from operator import itemgetter
data = file(sys.argv[1]).read().splitlines()

T = int(data.pop(0))

def fact(N):
    out = 1
    for i in xrange(2,N+1):
        out = (out * i) % 1000000007
    return out

def brute(TRAIN):
    TRAIN = sorted(TRAIN)

    debugon = False

    DATA = []
    for i in xrange(0,len(TRAIN)):
        s = TRAIN[i]
        letterused = set()
        lastlet = s[0]
        for j in xrange(0,len(s)):
            if s[j] in letterused:
                if s[j] != lastlet:
                    return 0
            letterused.add(s[j])
            lastlet = s[j]
        start = s[0]
        end = s[-1]
        perm = 1
        DATA.append((start,end,letterused,perm))

    if debugon:
        print 'initial'
        for i in DATA:
#            print TRAIN[i]
            print i

    # join all same segs
    DATA2 = []
    while len(DATA):
        (start,end,used,perm) = DATA.pop(0)
        num = 1
        if len(used) == 1:
            while len(DATA):
                (start2,end2,used2,perm2) = DATA[0]
                if len(used2) == 1 and start2 == start and end2 == end and start == end:
                    # join
                    assert(perm2 == 1)
                    assert(perm == 1)
                    num = num + 1
                    DATA.pop(0)
                    continue
                else:
                    break
        perm = fact(num)
        DATA2.append((start,end,used,perm))

    DATA = DATA2

    if debugon:
        print 'joined'
        for i in DATA:
            print i
    
    joined = 1
    while joined:
        joined = 0
        DATA = sorted(DATA, key=itemgetter(1))
        DATA = sorted(DATA, key=itemgetter(0))
        for i in xrange(0,len(DATA)):
            (start,end,used,perm) = DATA[i]
            for j in xrange(0,len(DATA)):
                if i == j:
                    continue
                (start2,end2,used2,perm2) = DATA[j]
                if start2 != end2:
                    continue
                if end == start2:
                    # join
#                    print 'match', DATA[i], DATA[j]
                    if len(used & used2) != 1:
                        return 0
                    perm = (perm * perm2) % 1000000007
#                    perm = (perm * 2) % 1000000007
                    DATA[i] = (start,end2,used|used2,perm)
                    DATA.pop(j)
                    joined = 1
                    break
            if joined:
                break
            for j in xrange(0,len(DATA)):
                if i == j:
                    continue
                (start2,end2,used2,perm2) = DATA[j]
                if end == start2:
                    # join
#                    print 'match', DATA[i], DATA[j]
                    if len(used & used2) != 1:
                        return 0
                    perm = (perm * perm2) % 1000000007
#                    perm = (perm * 2) % 1000000007
                    DATA[i] = (start,end2,used|used2,perm)
                    DATA.pop(j)
                    joined = 1
                    break
            if joined:
                break

    if debugon:
        print 'merged'
        for i in DATA:
            print i

    # check for conflicts
    for i in xrange(0,len(DATA)):
        (start,end,used,perm) = DATA[i]
        for j in xrange(0,len(DATA)):
            if i == j:
                continue
            (start2,end2,used2,perm2) = DATA[j]
            if len(used & used2):
                return 0

#    print 'no conflicts'

    out = 1
    for i in xrange(0,len(DATA)):
        (start,end,used,perm) = DATA[i]
        out = (out * perm ) % 1000000007

    out = (out * fact(len(DATA)))  % 1000000007
    return out
                
            
            

for numcase in xrange(1,T+1):
    print 'Case #%d:' % numcase,
    N = int(data.pop(0))
    TRAIN = [x for x in data.pop(0).split()]

    v = brute(TRAIN)
    print v



    

    

