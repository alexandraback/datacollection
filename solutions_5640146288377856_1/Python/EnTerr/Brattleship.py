#
# Google Code Jam 2015
# Roaund 1C: A. Brattleship
# submission by EnTerr
#

'''

Input 

3
1 4 2
1 7 7
2 5 1

Output 

Case #1: 3
Case #2: 7
Case #3: 10


'''

import sys
from time import clock


f = open(sys.argv[1])
def input(): return f.readline().strip();

def brat(r, c, w):
    n = r * (c // w)
    if c % w: n += 1  
    n += w-1
    return n

clk = clock()
#sys.setrecursionlimit(100000)

for caseNo in xrange(1, int(input())+1):
    r, c, w = map(int, input().split())
    #print >>sys.stderr, caseNo
    print 'Case #%d:' % caseNo, brat(r, c, w)
    
#print >>sys.stderr, 'time= %.1f seconds' % (clock()-clk )

