from math import sqrt

def isqrt(x):
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

f = open("input1.txt", "rb")
g = open("output1.txt", "wb")
n = int(f.readline().strip())
for y in xrange(n):
    r,t = map(int,f.readline().strip().split())
    a = 2
    b = 2*r - 1
    c = -t
    rootpart = isqrt(b**2-4*a*c)
    root1 = (rootpart-b)/(2*a)
    if root1>0:
        g.write("Case #%d: %d\n" % (y+1, root1))
    else:
        root2 = (rootpart+b)/(2*a)
        g.write("Case #%d: %d\n" % (y+1, root2))