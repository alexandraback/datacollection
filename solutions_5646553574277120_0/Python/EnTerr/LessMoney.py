#
# Google Code Jam 2015
# Roaund 1C: C. Less Money = More Problems
# submission by EnTerr
#

'''

Input 
 	
4
1 2 3
1 2
1 3 6
1 2 5
2 1 3
3
1 6 100
1 5 10 25 50 100

Output 
 
Case #1: 0
Case #2: 1
Case #3: 1
Case #4: 3


'''

import sys
from time import clock


f = open(sys.argv[1])
def input(): return f.readline().strip();

def lessMoney(c, d, v):
    n = 0
    for i in range(1, v+1):
        lst = [ i ]
        for j in d:
            lst += [x-j for x in lst if j <= x]
        x = min(lst)
        if x > 0:
            #print x, 
            d += [i]
            n += 1
    return n

clk = clock()
#sys.setrecursionlimit(100000)

for caseNo in xrange(1, int(input())+1):
    c, _, v = map(int, input().split())
    d = map(int, input().split())
    #print >>sys.stderr, caseNo
    print 'Case #%d:' % caseNo, lessMoney(c, d, v)
    
#print >>sys.stderr, 'time= %.1f seconds' % (clock()-clk )

