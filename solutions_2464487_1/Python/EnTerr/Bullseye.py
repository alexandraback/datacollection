#
# Google Code Jam 2013
# Round 1A: Bullseye
# submission by EnTerr
#

'''

Limits
Small dataset   1 <= T <= 1000. 1 <= r, t <= 1000.
Large dataset   1 <= T <= 6000. 1 <= r <= 10^18. 1 <= t <= 2 * 10^18.

Sample
*** Input 
5
1 9
1 10
3 40
1 1000000000000000000
10000000000000000 1000000000000000000

*** Output  
Case #1: 1
Case #2: 2
Case #3: 3
Case #4: 707106780
Case #5: 49

'''

#import psyco
#psyco.full()

import sys
from time import clock

inf = open(sys.argv[1])
def input(): return inf.readline().strip()

def isqrt(n):
    r0 = 1
    r1 = n
    while abs(r0 - r1) >= 1:
        r0 = r1
        r1 = (n/r0 + r0) / 2
        # print r1    
    return r1

def get_num_rings(r, t):
    r1 = 2*r - 1
    # calculate approximate solution 
    x = int((-r1 + isqrt(r1**2 + 8*t)) / 4)
    #for i in range(x-3, x+3):
    #    print i, t, 2*i*i + r1*x, 2*i*i + r1*x <= t
    return x



for caseNo in range(1, int(input())+1):
    #tm = clock()
    r, t = map(int, input().split())
    print 'Case #%d:' % caseNo, get_num_rings(r, t)
    #print >>sys.stderr, caseNo, clock() - tm

