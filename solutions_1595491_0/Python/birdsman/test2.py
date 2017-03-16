import operator
import itertools
import functools
import math

     
fn = open('1.in')
ofn = open('1.out', 'w')
TC = int(fn.readline())
for tc in range(TC):
    L = map(int, fn.readline().strip().split())
    N, S, p = L[0:3]
    pts = L[3:]
    if p == 0:
        minPtsForS = 0
        minPtsForNS = 0
    elif p == 1:
        minPtsForS = 1
        minPtsForNS = 1
    else:
        minPtsForS = 3*p-4
        minPtsForNS = 3*p-2
    #print minPtsForS, minPtsForNS
    potLi = [x for x in pts if x < minPtsForNS]
    res = len(pts) - len(potLi)
    potLi = [x for x in potLi if x >= minPtsForS]
    res += min([len(potLi), S])
    #print res
    
    #print tc       
    print >>ofn, 'Case #{}: {}'.format(tc +1, res)
        
        
