import sys
import fractions

T = int(sys.stdin.readline().strip())

def powerOfTwo(n):
    return (n <> 0) and ((n & (n - 1)) == 0)


for testNum in range(T):
    P, Q = map(int, sys.stdin.readline().strip().split("/"))

    f = fractions.Fraction(P, Q)
    
    if not powerOfTwo(f.denominator):
        ans = "impossible"
    else:
        fact = 0
        while f < 2 ** (-fact):
            fact += 1

        ans = str(fact)


    print "Case #%d: %s"%(testNum+1, ans)