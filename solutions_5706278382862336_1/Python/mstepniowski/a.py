import sys
from fractions import Fraction


POWERS_OF_TWO = [1]
for x in range(40):
    POWERS_OF_TWO.append(POWERS_OF_TWO[-1] * 2)

def solve(p, q):
    f = Fraction(p, q)
    if f.denominator not in POWERS_OF_TWO:
        return 'impossible'
    for i, pow in enumerate(POWERS_OF_TWO):
        if Fraction(1, pow) <= f:
            return i
    return 'impossible'


if __name__ == '__main__':
    case_count = int(sys.stdin.readline()[:-1])
    for i in range(1, case_count + 1):
        p, q = [int(x) for x in sys.stdin.readline().strip().split('/')]
        print "Case #%d: %s" % (i, solve(p, q))
