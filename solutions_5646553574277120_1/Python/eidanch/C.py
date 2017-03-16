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
    count = 0
    partial_sum = 0
    index = 0
    while partial_sum * C < V:
        if index < len(denoms) and denoms[index] <= partial_sum * C + 1:
            partial_sum += denoms[index]
            index += 1
        else:
            partial_sum += partial_sum * C + 1
            count += 1
    return count


def is_possible(v, denoms, c, counts=None, s=None):
    if counts is None:
        counts = len(denoms)*[0]
        s = 0
    if s > v:
        return False
    if s == v:
        #print v, list(zip(denoms, counts))
        return True
    for i in xrange(len(denoms)):
        if counts[i] < c:
            counts[i] += 1
            if is_possible(v, denoms, c, counts, s + denoms[i]):
                return True
            counts[i] -= 1
    return False


def handle_case_old(case):
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