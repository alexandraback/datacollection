__author__ = 'eidanch'

from itertools import combinations

def get_line():
    return raw_input().strip()

formatIntegerList = lambda s: list(map(int, s.split(' ')))


def standard_input():
    T = int(get_line())
    for i in range(T):
        params = tuple(map(int,get_line().split(' ')))
        denoms = list(map(int,get_line().split(' ')))
        yield (i+1, (params, denoms))


def handle_case(case):
    params, denoms = case
    C, D, V = params
    base = range(1, V)
    if test_cover(denoms, V, C):
        return 0
    for i in xrange(1, len(base)+1):
        for comb in combinations(base, i):
            if test_cover(denoms + list(comb), V, C):
                return i
    return None

def test_cover(denoms, V, C):
    assert C == 1
    tester = (V+1)*[False]
    tester[0] = True
    for r in xrange(1, len(denoms)+1):
        for comb in combinations(denoms, r):
            if sum(comb) <= V:
                tester[sum(comb)] = True
    return all(tester)

def main():
    for i, case in standard_input():
        print "Case #%d: %d" % (i, handle_case(case))

if __name__ == '__main__':
    main()