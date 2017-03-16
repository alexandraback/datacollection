import sys
import time
from itertools import permutations, combinations

in_name = sys.stdin
out_name = sys.stdout

fin = sys.stdin
fout = sys.stdout

class inout:
    IN = fin
    
    @classmethod
    def line(cls, type=str):
        return type(cls.IN.readline().strip())
        
    @classmethod 
    def splitline(cls, type=str):
        return [type(x) for x in cls.IN.readline().split()]


T = inout.line(int)
result = []

t1 = time.time

def solve(tbox, ttoy):
    #print 'box', tbox
    #print 'toy', ttoy
    if not tbox or not ttoy:
        return 0
    val = 0
    if tbox[0][0] == ttoy[0][0]:        
        if (tbox[0][1] < ttoy[0][1]):
            val = tbox[0][1]
            ttoy[0] = (ttoy[0][0], ttoy[0][1] - val)
            val += solve(tbox[1:], ttoy[:])
        elif (tbox[0][1] > ttoy[0][1]):
            val = ttoy[0][1]
            tbox[0] = (tbox[0][0], tbox[0][1] - val)
            val += solve(tbox[:], ttoy[1:])
        else:
            val = ttoy[0][1]
            val += solve(tbox[1:], ttoy[1:])
    else:
        val1 = solve(tbox[1:], ttoy[:])
        val2 = solve(tbox[:], ttoy[1:])
        val += max(val1, val2)
    
    return val
            
    
for test in range(int(T)):
    #Read input
    N, M = inout.splitline(int)
    boxs = inout.splitline(int)
    toys = inout.splitline(int)
    tbox = [(boxs[2*i+1], boxs[2*i]) for i in range(N)]
    ttoy = [(toys[2*i+1], toys[2*i]) for i in range(M)]
    matchs = []
    #print tbox, ttoy
    v = solve(tbox, ttoy)
    result.append("Case #%d: %d\n" % (test+1, v))
    
    

fout.writelines(result)
fout.close()
fin.close()
t2 = time.time
#print t2 - t1