#!/usr/bin/python

import sys
import numpy as np

def playwar(naomi, ken):
    naomi.sort()
    ken.sort()
    naomi, ken = naomi[:], ken[:]
    pts = 0
    while naomi:
        if naomi[-1] > ken[-1]:
            naomi.pop(-1)
            ken.pop(0)
            pts += 1
        else:
            naomi.pop(-1)
            ken.pop(-1)
    return pts

def playdeceit(naomi, ken):
    # already sorted
    n, k = np.array(naomi), np.array(ken)
    while not np.all(n > k):
        n = n[1:]
        k = k[:-1]
    return len(n)

f = open(sys.argv[1])
o = open(sys.argv[2], 'w')
cases = int(f.readline())
for i in xrange(cases):
    N = int(f.readline())
    naomi = map(float, f.readline().split())
    ken = map(float, f.readline().split())
    z = playwar(naomi, ken)
    y = playdeceit(naomi, ken)
    o.write("Case #" + str(i+1) + ': ' + str(y) + ' ' + str(z) + '\n')
o.close()
print "Done, output written"
 
