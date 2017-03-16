#
# Google Code Jam 2013
# Round 1C: C. The Great Wall
# submission by EnTerr
#

'''
Input
The first line of the input gives the number of test cases, T. T test cases follow.
The first line of each test case gives the name of a member as a string of length L,
and an integer n. Each name consists of one or more lower-case English letters.

Output
For each test case, output one line containing "Case #x: y",
where x is the case number (starting from 1)
and y is the n-value of the member's name.

Limits
1 <= T <= 100.
0 < n <= L.

Small dataset   1 <= L <= 100.
Large dataset   1 <= L <= 10^6.
The input file will be no larger than 6MB.

Sample

*** Input 
4
quartz 3
straight 3
gcj 2
tsetse 2

*** Output 
Case #1: 4
Case #2: 11
Case #3: 3
Case #4: 11


'''

#import psyco
#psyco.full()
#sys.setrecursionlimit(2000)

import sys
from time import clock

inf = open(sys.argv[1])
def input(): return inf.readline().strip()

def get_n_value(name, n):
    def is_cons(x):
        return x not in 'aeiou'

    res = set()
    for i in xrange(len(name)-n+1):
        for j in xrange(i, i+n):
            if not is_cons(name[j]):
                break
        else:
            # found a range
            for ii in xrange(0, i+1):
                for jj in xrange(j, len(name)):
                    res.add( (ii, jj) )
        
    #print res                
    return len(res)

for caseNo in range(1, int(input())+1):
    #tm = clock()
    #N = int(input())
    #tribes = [map(int, input().split()) for _ in xrange(N)]
    name, n = input().split()
    print 'Case #%d:' % caseNo, get_n_value(name, int(n))
    #print >>sys.stderr, caseNo, clock() - tm

