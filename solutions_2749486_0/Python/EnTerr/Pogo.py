#
# Google Code Jam 2013
# Round 1C: B. Pogo
# submission by EnTerr
#

'''
Input
The first line of the input gives the number of test cases, T.
T test cases follow, one per line.
Each line consists of 2 integers separated by a single space, X and Y,
the coordinates of the point you want to reach.

Output
For each test case, output one line containing "Case #x: y",
where x is the case number (starting from 1)
and y is a string represents the directions of the moves, for example
if you are going to move north then south then east then west, this string should be NSEW. 

For the small dataset, the output is considered correct if it does
not take more than 500 moves to reach the destination in each test case. 

For the large dataset, the output is considered correct if it reaches
the destination point in the minimum possible number of moves. 

Limits

Small dataset   1 <= T <= 50. 0 <= |X|, |Y| <= 100.

Large dataset   1 <= T <= 100. 0 <= |X|, |Y| <= 106.

Sample
*** Input 
2
3 4
-3 4
 	
*** Output 
Case #1: ENWSEN
Case #2: ENSWN

'''

#import psyco
#psyco.full()
#sys.setrecursionlimit(2000)

import sys
from time import clock

inf = open(sys.argv[1])
def input(): return inf.readline().strip()

def getPogoRoute(x,y):
    res = ''
    # evil hack, two consequent moves negate each other with delta=1
    dx = 'WE' if x>0 else 'EW'
    for _ in range(abs(x)):
        res += dx
    dy = 'SN' if y>0 else 'NS'
    for _ in range(abs(y)):
        res += dy        
    return res

for caseNo in range(1, int(input())+1):
    #tm = clock()
    X, Y = map(int, input().split())
    print 'Case #%d:' % caseNo, getPogoRoute(X, Y)
    #print >>sys.stderr, caseNo, clock() - tm

