__author__ = 'David'

import sys

T = int(sys.stdin.readline())

for N in xrange(T):
    k, c, s = [int(x) for x in sys.stdin.readline().strip().split(' ')]
    #print k, c, s
    looks = []
    pos = 1
    step = k ** c / k
    while pos <= k ** c:
        looks.append(str(pos))
        #print looks, pos
        pos += step
    #print
    print "Case #%d: %s" % (N + 1, ' '.join(looks))
