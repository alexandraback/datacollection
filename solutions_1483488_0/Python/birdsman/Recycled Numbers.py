import operator
import itertools
import functools
import math

def rot(i, B):
    s = str(i)
    r = set()
    for j in range(1, len(s)):
        x = s[j:]+s[:j]
        if B >= int(x) > i:
            r.add(x)
    return len( r )
    

fn = open('1.in')
ofn = open('1.out', 'w')
TC = int(fn.readline())
for tc in range(TC):
    A, B = map(int, fn.readline().strip().split())
    res = 0
    for i in range(A, B+1):
        res += rot(i, B)
    #print res
    #print len(rs)
    #print tc       
    print >>ofn, 'Case #{}: {}'.format(tc +1, res)
        
        
