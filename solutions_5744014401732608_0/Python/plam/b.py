#!/usr/bin/python

import sys, collections

def brute( B, M ):
    if M > 1 << (B-2):
        print 'IMPOSSIBLE'
        return
    else:
        print 'POSSIBLE'
        if M == 1 << (B-2):
            print '0' + '1'*(B-1)
        else:
            out = '0'
            cur = 1<< (B-3)
            while (cur):
                if M >= cur:
                    out = out + '1'
                    M = M - cur
                else:
                    out = out + '0'
                cur = cur / 2
            print out + '0'
        for i in xrange(0,B-2):
            print '0'*(i+2) + '1'*(B-i-2)
        print '0'*B

        

data = file(sys.argv[1]).read().splitlines()

NUMCASE = int(data.pop(0))

for CASE in xrange( 1, NUMCASE + 1 ):
    print 'Case #%d:' % ( CASE, ),
    (B, M) = [int(x) for x in data.pop(0).split()]
    brute(B, M)

        
