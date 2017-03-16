from DomainModel.TestCase import TestCase
import collections
import random
from fractions import Fraction
import itertools


def rem(inx, code, d, a, ch):
    a[inx] = d[ch]
    for c in code[inx]:
        d[c] -= a[inx]

class R2A:
    def Solve(self):
        code = ["ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"]
        tests = int(input())
        # a = list(map(int, input().split()))
        for test in range(tests):
            txt = input().strip()
            d = collections.defaultdict(lambda: 0)
            for x in txt:
                d[x] += 1
            a = [0 for x in range(10)]

            rem(0, code, d, a, 'Z')
            rem(2, code, d, a, 'W')
            rem(4, code, d, a, 'U')
            rem(6, code, d, a, 'X')
            rem(8, code, d, a, 'G')
            rem(1, code, d, a, 'O')
            rem(3, code, d, a, 'H')
            rem(5, code, d, a, 'F')
            rem(7, code, d, a, 'S')
            rem(9, code, d, a, 'I')

            ret=''
            for i,x in enumerate(a):
                ret += str(i)*x

            print("Case #{}: {}".format(test + 1, ret))

    def Tests(self):
        yield TestCase("""4
OZONETOWER
WEIGHFOXTOURIST
OURNEONFOE
ETHER
""", """Case #1: 012
Case #2: 2468
Case #3: 114
Case #4: 3
""")
