import math, fractions
def solve(case):
    P, Q = case
    gcd = fractions.gcd(P, Q)
    P = P/gcd
    Q = Q/gcd
    if 2**40 % Q != 0:
        return "impossible"
    R = P * 2**40 / Q
    return 40 - int(math.floor(math.log(R,2)))

def read_case(f):
    P, Q = tuple(map(int, f.readline().split("/")))
    return P, Q

if __name__ == "__main__":
    import sys
    f = sys.stdin
    T = int(f.readline())
    for case_num in range(1, T+1):
        case = read_case(f)
        print "Case #"+str(case_num)+": "+str(solve(case))
