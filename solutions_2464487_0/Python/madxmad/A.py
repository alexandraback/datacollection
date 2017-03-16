MAXN = 1000000000L

def f(r,n):
    v = 2*r*n - 3*n + 2*n*(n+1);
    return v

def bs(r,t,a,b):
    if(a == b): return a
    if(b - a == 1):
        v = f(r,b)
        if(v <= t): return b
        return a

    if(a >= b): return min(a,b)
    m = (a + b)/2
    v = f(r,m)
    
    if(v < t): return bs(r,t,m,b)
    if(v > t): return bs(r,t,a,m);
    return m

def solve(r, t):
    return bs(r,t,0,MAXN);

file_in = open("A.in")
file_out = open("A.out",'w')

t = int(file_in.readline())

for ncase in range(1,t+1):
    v = file_in.readline().split()
    r = int(v[0])
    t = int(v[1])
    ans = solve(r,t)
    file_out.write("Case #%s: %s\n" % (ncase,ans))

file_out.close()
