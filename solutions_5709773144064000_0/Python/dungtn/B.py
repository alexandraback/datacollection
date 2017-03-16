from __future__ import division
from sys import argv

f = open(argv[1], 'r')

T = int(f.readline()[:-1])
for case in xrange(1,T+1):
    C, F, X = map(float, f.readline()[:-1].split(' '))
    R       = 2
    t       = 0
    while True:
        if C/R + X/(R+F) < X/R:
            t += C/R
            R += F
        else:
            t += X/R
            break
    print "Case #%d: %.7f" % (case, t)
