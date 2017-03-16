#!/usr/bin/python

import sys, collections

def brute2( J, P, S, K ):
    t1 = J*P
    t2 = min(S,K)
    print t1*t2
    JP = collections.defaultdict(int)
    JI = collections.defaultdict(int)
    PI = collections.defaultdict(int)
    
    for i in xrange(1,t2+1):
        for j in xrange(1,J+1):
            for p in xrange(1,P+1):
                print j, p, i
                JP[(j,p)] = JP[(j,p)] + 1
                assert JP[(j,p)] <= K
                JI[(j,i)] = JI[(j,i)] + 1
                assert JI[(j,i)] <= K
                PI[(p,i)] = PI[(p,i)] + 1
                assert PI[(p,i)] <= K

def brute( J, P, S, K ):
    t1 = J*P
    t2 = min(S,K)
    JP = collections.defaultdict(int)
    JI = collections.defaultdict(int)
    PI = collections.defaultdict(int)
    
    out = ''
    total = 0
    outset = set()
    while True:
        found = False
        mincost = 999999
        for i in xrange(1,S+1):
            for j in xrange(1,J+1):
                for p in xrange(1,P+1):
                    if (j,p,i) in outset:
                        continue
                    if JP[(j,p)] == K:
                        continue
                    if JI[(j,i)] == K:
                        continue
                    if PI[(p,i)] == K:
                        continue
                    if JP[(j,p)] + JI[(j,i)] + PI[(p,i)] < mincost:
                        mincost = JP[(j,p)] + JI[(j,i)] + PI[(p,i)]
                        mint = (j, p, i)
                        found = True
        if not found:
            break
        (j,p,i) = mint
        outset.add(mint)
        JP[(j,p)] = JP[(j,p)] + 1
        JI[(j,i)] = JI[(j,i)] + 1
        PI[(p,i)] = PI[(p,i)] + 1
        out = out + "%d %d %d\n" %( j, p, i )
        total = total + 1

    print total
    print out[:-1]
                

data = file(sys.argv[1]).read().splitlines()

NUMCASE = int(data.pop(0))

for CASE in xrange( 1, NUMCASE + 1 ):
    print 'Case #%d:' % ( CASE, ),
    (J, P, S, K) = [int(x) for x in data.pop(0).split()]
    brute( J, P, S, K )

        
