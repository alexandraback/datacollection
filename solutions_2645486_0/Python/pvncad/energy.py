#/usr/local/bin/python

import sys
import math

def maximize_1(initE, E, R, N, values):

    ans = dict()

    for i in xrange(N):
        newans = dict()
        for e in xrange(E + 1):
            if e == 0:
                newans[e] = ans.get(e, 0)
            else:
                maxgain = 0
                for ee in xrange(e + 1):
                    gain = ee * values[N - i - 1]
                    ie = e -  ee
                    ie = min(E, ie + R)
                    gain += ans.get(ie, 0)
                    maxgain = max(maxgain, gain)
                newans[e] = maxgain
        ans = newans

    return max(ans.values())



cache = dict()

def maximize(initE, E, R, N, values):

    ans = 0

    if N == 0:
        return ans

    key = (initE, N)

    if key in cache:
        return cache[key]

    for e in xrange(initE + 1):
        gain = e * values[0]

        newInit = initE - e
        if e > 0:
            newInit += R
        gain += maximize(min(E, newInit), E, R, N - 1, values[1:])

        ans = max(ans, gain)
        #print N, ans, gain

    cache[key] = ans
    return ans

T = int(sys.stdin.readline())

for caseno in xrange(T):
   E, R, N = [int(x) for x in sys.stdin.readline().split()]
   values  = [int(x) for x in sys.stdin.readline().split()]
   cache = dict()
   ans = maximize_1(E, E, R, N, values)

   print "Case #%d: %d" % (caseno + 1, ans)
