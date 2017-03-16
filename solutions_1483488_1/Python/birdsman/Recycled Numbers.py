import operator
import itertools
import functools
import math

lookUp = {}

def rot(i, B):
    s = str(i)
    r = set()
    for j in range(1, len(s)):
        x = s[j:]+s[:j]
        if B >= int(x) > i:
            r.add(int(x))
    if len(r) > 0:
        lookUp[i] = r
    return len( r )
    
def buildLookUp(A, B):
    for i in range(A, B+1):
        rot(i, B)

fn = open('1.in')
ofn = open('1.out', 'w')
TC = int(fn.readline())
buildLookUp(1, 2000000)
#print lookUp

for tc in range(TC):
    A, B = map(int, fn.readline().strip().split())
    res = 0
    for i in range(A, B+1):
        if i not in lookUp:
            continue
        for c in lookUp[i]:
            if c <= B:
                res += 1
    
    #print res
    #print len(rs)
    #print tc       
    print >>ofn, 'Case #{}: {}'.format(tc +1, res)
        
        
