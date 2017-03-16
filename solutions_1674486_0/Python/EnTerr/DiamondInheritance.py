#
# Google Code Jam 2012
# Round 1C: A. Diamond Inheritance
# submission by EnTerr
#

'''
Input 
3
3
1 2
1 3
0
5
2 2 3
1 4
1 5
1 5
0
3
2 2 3
1 3
0

Output 
Case #1: No
Case #2: Yes
Case #3: Yes

'''

#import psyco
#psyco.full()

import sys
from collections import defaultdict
from time import clock

inf = open(sys.argv[1])
def input(): return inf.readline().strip()

def hasDiamons(nodes):
    global paths
    notDone = True
    paths = defaultdict(lambda: defaultdict(list))
    for i in range(len(nodes)):
        #paths[i] = {}
        for j in nodes[i]:
            paths[i][j] = [i, j]
    while notDone:
        notDone = False
        for i in range(len(nodes)):
            for j in nodes[i]:
                #print paths
                for k in paths[j]:
                    if k not in paths[i]:
                        paths[i][k] = [i] + paths[j][k]
                        notDone = True
                    elif paths[i][k] != [i] + paths[j][k]:
                        return True
    return False

for caseNo in range(1, int(input())+1):
    #tm = clock()
    N = int(input())
    nodes = [[int(v)-1 for v in input().split()][1:] for node in range(N)]
    res = hasDiamons(nodes)
    print 'Case #%d:' % caseNo, 'Yes' if res else 'No'
    #print >>sys.stderr, caseNo, clock() - tm

