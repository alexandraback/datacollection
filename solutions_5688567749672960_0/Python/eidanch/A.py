__author__ = 'eidanch'

import sys

def get_line():
    return raw_input().strip()

formatIntegerList = lambda s: list(map(int, s.split(' ')))


def standard_input():
    T = int(get_line())
    for i in range(T):
        N = int(get_line())
        yield (i+1, N)


def handle_case(case):
    N = case
    lst = (N+1)*[None]
    lst[1] = 1
    for i in xrange(2, N+1):
        lst[i] = min(1 + lst[i - 1], lst[i] if lst[i] is not None else N)
        rev_i = int(''.join(reversed(str(i))))
        if i < rev_i <= N:
            lst[rev_i] = min(1 + lst[i], lst[rev_i] if lst[rev_i] is not None else N)
    return lst[N]


def recursive_solution(base, target):
    if base == target:
        return 1
    rbase = int(''.join(reversed(str(base))))
    if rbase <= base or rbase > target:
        return 1 + recursive_solution(base + 1, target)
    else:
        return 1 + min(recursive_solution(base + 1, target), recursive_solution(rbase, target))


def main():
    for i, case in standard_input():
        print "Case #%d: %d" % (i, handle_case(case))

if __name__ == '__main__':
    main()