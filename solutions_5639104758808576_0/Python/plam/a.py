#!/usr/bin/python
import sys, collections

data = file(sys.argv[1]).read().splitlines()

T = int(data.pop(0))

for numcase in xrange(1,T+1):
    print 'Case #%d:' % numcase,
    ( SMAX, K ) = data.pop(0).split()
    SMAX = int(SMAX)
    cur = 0
    invite = 0
    for i in xrange(0,SMAX+1):
        if int(K[i]) and cur < i:
#            print 'inviting',cur, i,(i - cur)
            invite = invite + (i - cur)
            cur = cur + invite
        cur = cur + int(K[i])
    print invite

    
