from itertools import combinations
import sys

_in = open(sys.argv[1])
def raw(): return _in.readline().rstrip('\n')
def ints(): return map(int, raw().split())
raw_input = raw # we all forget sometimes

def solve(L):
    n = len(L)
    for j in range(n-2, 0, -1):
        for orig in combinations(range(n), n-j):
            left = set()
            right = set()
            for i in orig:
                left.add(L[i][0])
                right.add(L[i][1])
            good = True
            for i in range(n):
                if i not in orig:
                    if L[i][0] not in left or L[i][1] not in right:
                        good = False
                        break
            if good:
                return j
    return 0

if __name__ == '__main__':
    num_cases, = ints()
    for case_num in xrange(1, num_cases + 1):
        N, = ints()
        L = []
        for i in range(N):
            L.append(tuple(raw().split()))
        print "Case #{}: {}".format(case_num, solve(L))
