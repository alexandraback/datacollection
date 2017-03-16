##
# CODEJAM
# prillan91
##
import sys

def solveSingle(f):
    C, F, X = tuple(float(x) for x in f.readline().strip().split(' '))

    s = 0
    n = 0

    while True:

        if (C - X)/(2 + n*F) + X/(2 + (n+1)*F) > 0:
            return C*s + X/(2+n*F)

        s += 1/(2+n*F)
        n += 1

def solve():
    f = open(sys.argv[1])
    o = open(sys.argv[1] + ".out", 'w')
    T = int(f.readline())

    for t in range(T):
        print t + 1
        o.write("Case #" + str(t + 1) + ": " + str(solveSingle(f)) + "\n")
        


solve()
