#!/usr/bin/python
import sys, collections

data = file(sys.argv[1]).read().splitlines()

T = int(data.pop(0))

def fast(PI):
    D = collections.defaultdict(int)
    for v in PI:
        D[v] = D[v] + 1
    K = sorted(D.keys(),reverse=True)
#    print D
#    print K
    
    MAX = K[0]
    MIN = K[0]
    for i in xrange(MAX-1,0,-1):
        ROUND = i
        for k in K:
            if i >= k:
                continue
            if k % i:
                TR = k/i
            else:
                TR = k/i - 1
            ROUND = ROUND + ( TR*D[k] )
        if ROUND < MIN:
            MIN = ROUND
    return MIN

def brute(round, PI, min):
    if round+PI[0] < min:
        min = round+PI[0]
    if round >=min:
        return min

    if PI[0] == 1:
        assert min >= round+1
        return round+1
    for i in xrange(1,PI[0]/2+1):
        pid = PI[:]
        top = pid.pop(0)
        pid.append(i)
        pid.append(top-i)
        pid.sort(reverse=True)
#        print round, min, pid
        n = brute(round+1,pid,min)
        if n < min:
            min = n
    return min

for numcase in xrange(1,T+1):
    print 'Case #%d:' % numcase,
    D = int(data.pop(0))
#    print D
    s = data.pop(0)
#    print s, s.split()
    PI = [int(x) for x in s.split()]
    PI.sort(reverse=True)
    f = fast(PI[:])
#    b = brute(0, PI[:],PI[0])
#    assert f == b
    print fast(PI[:])

#    print brute(0, PI[:],PI[0]), PI
#    print brute(0, PI[:],PI[0])

