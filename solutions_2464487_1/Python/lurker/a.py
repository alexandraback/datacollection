import math
import sys

rl = sys.stdin.readline


def sol(r, P):
    a = 2.
    b = (2*r - 1)
    c = - P
    df = math.sqrt(b**2. - 4 * a * c)
    sol1 = (- b + df ) / 4.
    sol2 =  (- b - df ) / 4.
    #    print (sol1, sol2)

    return max([0,int(math.floor(sol1)), int(math.floor(sol2))])


n = int(rl())
for i in range(n):
    r, P = map(int, rl().split())
    print ("Case #%d: %d"%(i+1, sol(r,P)))
