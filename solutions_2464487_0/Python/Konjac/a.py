import sys

def solve():
    r, t = map(int,sys.stdin.readline().split()) 
    L = 1
    R = t;
    while L+1<R:
        mid = ( L + R )/2;
        a0 = 2*r+1
        v = a0*mid + mid*(mid-1)/2*4
        if v<=t:
            L = mid
        else:
            R = mid
    print L

T = int(sys.stdin.readline())
for t in range(1,T+1):
    print "Case #" + str(t) + ":",
    solve()
    
