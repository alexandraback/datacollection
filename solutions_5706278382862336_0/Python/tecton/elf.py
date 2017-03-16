import sys
from fractions import Fraction
sys.stdin = open('input', 'r')

def solve(P, Q):
    v = Fraction(P, Q)
    minA = 50
    for i in range(1, 41):
        n1 = 2 * v - 1
        n0 = 2 * v
        if n1 >= 0 and n1 <= 1:
            minA = min(i, minA)
            v = n1
        if n1 == 0 or n1 == 1:
            return repr(minA)
        elif n1 < 0 and n0 >= 0 and n0 <= 1:
            v = n0
    return 'impossible'

numcases = int(sys.stdin.readline())
for casenum in range(1, numcases + 1):
    P, Q = [int(n) for n in sys.stdin.readline().split('/')]
    print 'Case #' + repr(casenum) + ': ' + solve(P, Q)
