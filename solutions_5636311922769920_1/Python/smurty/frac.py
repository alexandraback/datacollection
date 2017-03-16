#!/usr/bin/env python

T = input()
for t in xrange(1, T+1):
    K, C, S = map(int, raw_input().strip().split())
    print 'Case #{}:'.format(t),
    d = K//C + int(K % C > 0)
    if S >= d:
        print ' '.join(str(1+sum(K**e * y for e,y in enumerate(xrange(C*x,min(K,C*(x+1))))))
                       for x in xrange(d))
    else:
        print 'IMPOSSIBLE'
