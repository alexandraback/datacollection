import math, numpy, sys, itertools
from collections import defaultdict

def solve_case(N, S):
    sums = defaultdict(set)
    for c in range(1, 19):
        sys.stderr.write('comb=%d\n' % c)
        for choose in itertools.combinations(S, c):
            cs = sum(choose)
            sums[cs].add(frozenset(choose))

    for ssum, sumset in sums.items():
        if len(sumset) < 2:
            continue
        sumset = list(sumset)
        while True:
            s = sumset.pop()
            for other in sumset:
                if s.isdisjoint(other):
                    result = [' '.join([str(i) for i in s])]
                    result.append(' '.join([str(i) for i in other]))
                    return '\n' + ('\n'.join(result))
    return 'Impossible'
    return result


def read_case(instream):
    ints = [int(ns) for ns in instream.readline().strip().split()]
    N = ints[0]
    S = ints[1:]
    return N, S


def do_cases(instream):
    T = int(instream.readline())
    for t in range(1, T + 1):
        case_params = read_case(instream)
        result = solve_case(*case_params)
        print('Case #%d: %s' % (t, result))
        t += 1


if __name__ == '__main__':
#    do_cases(open('test.in', 'r'))
    do_cases(sys.stdin)

