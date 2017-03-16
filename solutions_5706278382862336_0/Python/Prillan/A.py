##
# CODEJAM
# prillan91
##
import math
import sys

def gcd(a, b):
    if b > a:
        return gcd(b, a)
    x, y = a, b
    while y != 0:
        x, y = y, x % y
    return x

def simplify(p, q):
    d = gcd(p, q)
    return p // d, q // d

def weaklog2(x):
    power = 0
    while x > 1:
        if x & 1 == 1:
            return False
        x = x // 2
        power += 1
    return power

def biggest2pow(x):
    power = 0
    while 2 ** power <= x:
        power += 1
    return power - 1

def solveSingle(f):
    P, Q = [int(x) for x in f.readline().split('/')]

    print("{}/{}".format(P, Q))
    P, Q = simplify(P, Q)
    print(" s: {}/{}".format(P, Q))

    power = weaklog2(Q)

    if power is False:
        print("  impossible")
        return "impossible"

    bpower = biggest2pow(P)
    print("  {}".format(bpower))

    p, q = simplify(2 ** bpower, Q)
    print("  {}/{}".format(p, q))
    power = weaklog2(q)
    print("  {}".format(power))
    return power

def solve():
    f = open(sys.argv[1])
    o = open(sys.argv[1] + ".out", 'w')
    T = int(f.readline())

    for t in range(T):
        print(t + 1)
        o.write("Case #" + str(t + 1) + ": " + str(solveSingle(f)) + "\n")

if __name__ == "__main__":
    solve()
