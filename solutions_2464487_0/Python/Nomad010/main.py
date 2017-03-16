import sys
sys.setrecursionlimit(10000)
T = int(raw_input())

def F(r, i):
    return 2*r*i + 2*i*(i-1) + i

def Solve(r, t, small, large):
    med = (small + large)/2
    val = F(r, med)
    nval = F(r, med + 1)
    
    if val <= t and nval > t:
        return med
        
    if nval <= t:
        return Solve(r, t, med, large)
    
    if val >= t:
        return Solve(r, t, small, med)
        
    #print val, t, nval
        
for c in xrange(1, T + 1):
    r, t = map(int, raw_input().split())
    
    Solve(r, t, 1, 10**100)
    print "Case #%d: %d" %(c, Solve(r, t, 1, 10**100))
    