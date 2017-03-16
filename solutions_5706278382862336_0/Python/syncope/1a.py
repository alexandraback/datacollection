from __future__ import division
import bisect
from fractions import Fraction as F, gcd

import sys
sys.setrecursionlimit(10000)
EXAMPLE_IN = """\
5
1/2
3/4
1/4
2/23
123/31488
"""

EXAMPLE_OUT = """\
Case #1: 1
Case #2: 1
Case #3: 2
Case #4: impossible
Case #5: 8
"""

def make_gens(n):
    gens = [[(F('0')), (F('1'))]]
    for i in range(1, n):
        new_gen = set()
        last_gen = gens[-1]
        N = len(last_gen)
        for i in range(N):
            # for j in range(i, N):
            #     print last_gen[i], last_gen[j], (last_gen[i] + last_gen[j])/2
            #     new_gen.add((last_gen[i] + last_gen[j])/2)
            new_gen.update((last_gen[i] + last_gen[j])/2 for j in range(i, N))
        gens.append(sorted(new_gen))
    return gens

DENOM = 1<<40
DIVISIONS = [-(DENOM >> i) for i in range(40)]
def solve(p, q):
    d = gcd(p, q)
    p = p//d
    q = q//d
    if gcd(q, DENOM) != q or p > DENOM or p == 0:
        return 'impossible'
    p *= (DENOM//q)
    pos = bisect.bisect_left(DIVISIONS, -p)
    return pos


def main(lines):
    for i in xrange(int(next(lines))):
        p, q = map(int, next(lines).split('/'))
        ans = 'Case #%d: %s' % (i+1, solve(p, q))
        print ans




if __name__ == '__main__':
    if len(sys.argv) == 1:
        input = iter(EXAMPLE_IN.split('\n'))
        print 'Should be\n', EXAMPLE_OUT
    else:
        input = open(sys.argv[1])
    main(input)
