#!/usr/bin/python

import sys

f = open(sys.argv[1])
o = open(sys.argv[2], 'w')
cases = int(f.readline())
for i in xrange(cases):
    f0 = 2.
    C, F, X = map(float, f.readline().split())
    curTime = X/f0
    newTime = C/f0 + X/(f0+F)
    upto = 0.
    while newTime < curTime:
        upto = upto + C/f0
        f0 = f0 + F
        curTime = newTime
        newTime = upto + C/f0 + X/(f0+F)
    o.write("Case #" + str(i+1) + ': {:1.7f}\n'.format(curTime))


o.close()
print "Done, output written"
 
