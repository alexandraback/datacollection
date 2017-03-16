import sys
from fractions import gcd


MAX_GEN = 40


def solve(a, b):
    g = gcd(a, b)
    a0 = a / g
    b0 = b / g
    for d in range(MAX_GEN + 1):
        if b0 == (1 << d):
            for k in range(d + 1):
                if (a0 & (1 << (d - k))):
                    return k

    return "impossible"


if __name__ == '__main__':
    T = int(sys.stdin.readline())
    for t in range(T):
        a, b = map(int, sys.stdin.readline().split('/'))
        answer = solve(a, b)
        print "Case #{0}: {1}".format(t + 1, answer)
