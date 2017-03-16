#
# Google Code Jam 2013
# Round 1C: C. The Great Wall
# submission by EnTerr
#

'''
Input
The first line of the input gives the number of test cases, T.
T test cases follow. Each test case begins with a line containing a single integer N:
the number of the tribes attacking the Wall.
N lines follow, each describing one tribe. The ith line contains eight integers
di, ni, wi, ei, si, delta_di, delta_pi and delta_si
separated by spaces, describing a single nomadic tribe:

Output
For each test case, output one line containing "Case #x: y",
where x is the case number (starting from 1) and y is the number of attacks that succeed.

Limits
1 <= T <= 20.
0 <= di.
1 <= delta_di <= 676060.
di + (ni - 1) * delta_di <= 676060.
1 <= si <= 106.
-105 <= delta_si <= 105.
si + (ni - 1) * delta_si >= 1.

Small dataset
1 <= N <= 10.
1 <= ni <= 10.
-100 <= wi < ei <= 100.
-10 <= delta_pi <= 10.

Large dataset
1 <= N <= 1000.
1 <= ni <= 1000.
-10^6 <= wi < ei <= 10^6.
-10^5 <= delta_pi <= 10^5.

Sample
*** Input 
2
2
0 3 0 2 10 2 3 -2
10 3 2 3 8 7 2 0
3
1 2 0 5 10 2 8 0
0 3 0 1 7 1 2 2
3 3 0 5 1 1 4 0

*** Output 
Case #1: 5
Case #2: 6

'''

#import psyco
#psyco.full()
#sys.setrecursionlimit(2000)

import sys
from time import clock

inf = open(sys.argv[1])
def input(): return inf.readline().strip()

def getNumAttacks(tribes):
    from collections import defaultdict
    '''
    d - the day of the tribe's first attack (where 1st January, 250BC, is considered day 0)
    n - the number of attacks from this tribe
    w, e - the westmost and eastmost points respectively of the Wall attacked on the first attack
    s - the strength of the first attack
    delta_d - the number of days between subsequent attacks by this tribe
    delta_p - the distance this tribe travels to the east between subsequent attacks (if this is negative, the tribe travels to the west)
    delta_s - the change in strength between subsequent attacks
    '''
    attacks = defaultdict(list) # dictionary [day#] = list of attacks
    for tribe in tribes:
        d, n, w, e, s, delta_d, delta_p, delta_s = tribe
        for att_no in xrange(n):
            attacks[d].append( [w, e, s] )
            d += delta_d
            w += delta_p
            e += delta_p
            s += delta_s
    #print attacks
    # exploit that in simple case attacks are limited to -200 .. 200
    # and also that negative indexes wrap-around in python
    res = 0
    wall = [0] * 500
    for day in sorted(attacks):
        new_wall = wall[:]
        dtribes = attacks[day]
        for tribe in dtribes:
            w, e, s = tribe
            hit = False
            for pos in xrange(w, e):
                if s > wall[pos]:
                    hit = True
                    new_wall[pos] = max(s, new_wall[pos])
            if hit:
                res += 1
        wall = new_wall
            
    return res

for caseNo in range(1, int(input())+1):
    #tm = clock()
    N = int(input())
    tribes = [map(int, input().split()) for _ in xrange(N)]
    print 'Case #%d:' % caseNo, getNumAttacks(tribes)
    #print >>sys.stderr, caseNo, clock() - tm

