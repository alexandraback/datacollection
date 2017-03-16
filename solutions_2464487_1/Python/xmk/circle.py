
f=open("input")
ff=open("output", "w")
readint=lambda :int(f.readline())
readintarray=lambda :map(int, f.readline().split())
T=readint()

def slow(r,t):
    s=n=0
    while True:
        s += 2*(r+2*n) +1
        if s<=t:
            n+=1
        else:
            return n
def isqrt(x):
    if x < 0:
        raise ValueError('square root not defined for negative numbers')
    n = int(x)
    if n == 0:
        return 0
    a, b = divmod(n.bit_length(), 2)
    x = 2**(a+b)
    while True:
        y = (x + n//x)//2
        if y >= x:
            return x
        x = y
def fast(r,t):
    n=(isqrt( (2*r-1)**2 + 8*t )-2*r+1)/4
    return n

for casex in range(T):
    r,t = readintarray()
    print >>ff, "Case #%d:"%(casex+1), fast(r,t)
ff.close()
print "done"
"""
   i=1 to n
   (2*r+2*n-1)*n<=t
   2*n*n+(2*r-1)*n - t <=0

n=    -(2*r-1)+sqrt( (2*r-1)^2 + 4*2*t) /4
   

   2*(r+2*(i-1))+1 <=t
"""
