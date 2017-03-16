infile = "1Asmall.txt"

"""
Area of a ring with inner radius r cm is:
  pi((r+1)^2) - pi(r^2)
= pi(r^2 + 2r + 1) - pi(r^2)
= pi(2r + 1)

Area for n rings is:
= area(r) + area(r+2) + area(r+4)... + area(r + 2n - 2)
= pi(2r + 1) + pi(2r + 5) + pi(2r + 9)... + pi(2r + 4n - 3)
= pi(2rn) + 1pi + 5pi + 9pi... + (4n - 3)pi
= pi(2rn) + n(1 + (4n-3))pi/2
= pi(2rn + n(1 + (4n-3))/2)
= pi(2rn + n(4n - 2)/2)
= pi(2rn + n(2n - 1))
= npi(2r + 2n - 1)
= pi(2rn + 2n^2 - n)

For area = tpi, solve quadratic equation for n:
2n^2 + 2rn - (t + 1) = 0

Arithmetic series 1,5,9,...,4n-3 (a1 = 1):
Sum of a1 to an = n(a1 + an)/2
"""

def getPaint(r, n):
    return 2*n*n + 2*r*n - n

def solveQuad(a, b, c):
    # (-b +- sqrt(b^2 - 4ac)) / 2a
    sqrt = (b*b - 4*a*c) ** 0.5
    x1 = (-b + sqrt) / (2*a)
    #x2 = (-b - sqrt) / (2*a)
    return x1

def getPaintSingleRing(r):
    return ((r+1) * (r+1)) - (r*r)

def getPaintSimple(r, n):
    rv = 0
    for k in range(n):
        rv += getPaintSingleRing(r)
        r += 2
    return rv

def getMaxRings(r, t):
    x = int(solveQuad(2, 2*r, -(t+1)))
    while getPaint(r, x) < t:
        x += 1
    while getPaint(r, x) > t:
        x -= 1
    #print("%i,%i -> %i -> %i" % (r, t, x, getPaintSimple(r, x)-getPaint(r, x)))
    return x

def getMaxRingsSimple(r, t):
    k = 0
    while getPaintSimple(r, k+1) <= t:
        k += 1
    return k

with open(infile, "r") as f:
    with open("output.txt", "w") as o:
        nc = int(f.readline())
        for c in range(nc):
            r,t = f.readline().split(" ")
            r = int(r)
            t = int(t)
            o.write("Case #%i: %i\n" % (c+1, getMaxRings(r, t)))
