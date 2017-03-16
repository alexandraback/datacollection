#!/usr/bin/python

import sys

data = file( sys.argv[1] ).read().splitlines()

l = data.pop( 0 )
NUMCASE = int(l)


def brute( STR, N):
    run = 0
    start = 0
    vowel = set(['a','e','i','o','u'])
    val = 0
    for j in xrange(0,len(STR)):
#        print 'testing', STR[j:]
        run = 0
        for i in xrange(j,len(STR)):
            if STR[i] not in vowel:
#                print STR[i]
                run += 1
                if run >=N:
                    val += len(STR) - i
                    break
            else:
                run = 0
    return val
    

def calc( STR, N):
    # calc list of N
    run = 0
    start = 0
    vowel = set(['a','e','i','o','u'])
    V = []
    for i in xrange(0,len(STR)):
        if STR[i] not in vowel:
#            print STR[i]
            if run == 0:
                start = i
            run += 1
        else:
            if run >=N:
                V.append((start, i-1))
            run = 0
    if run >=N:
        V.append((start,i))
#    print V
    val = 0
    for i in xrange(0,len(STR)-N+1):
#        print 'testing', i, V
        if len(V) == 0:
            break
        start,end = V[0]
        while( i >= start and (end -i + 1 < N)):
#            print i, start,end,  end -i + 1 , N
            V.pop(0)
            if len(V) == 0:
                break
            start, end = V[0]
        if len(V):
            start, end = V[0]
            if i >= start:
                val += len(STR) - (i+N) + 1
                assert i+N-1 <= end
            else:
#                print 'eval', i, start, end, len(STR) - end, len(STR)
                val += len(STR) - end
    return val

for CASE in range(1,NUMCASE+1):
    print 'Case #%d:' % CASE,
    l = data.pop( 0 )
    STR, N = l.split(' ')
    N = int(N)
#    ans = calc( STR, N )
    ans2 = brute(STR,N)
#    print ans, ans2, STR, N
#    assert ans == ans2
    print ans2






