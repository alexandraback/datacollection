from __future__ import division
from __future__ import print_function
import itertools
from collections import defaultdict


def read_many(input_type=int):
    return map(input_type, raw_input().strip().split(' '))


def print_result(n, result):
    print('Case #%d: %s' % (n, result))


def read_task():
    return input()


def get_counts_to_reach_digits(ndigits):
    if ndigits == 2:
        return 10
    assert ndigits > 2

    result = get_counts_to_reach_digits(ndigits - 1)

    nstr = '9'*(ndigits - 1)
    return solve_for_order(int(nstr), nstr, result)


DEBUG = False
DEBUG = False

def solve_for_order(n, nstr, result_so_far):
    if DEBUG:
        print('solve_for_order(%d, %d)' % (n, result_so_far))

    ndigits_halved = len(nstr) // 2

    worst_case = n - 10**(len(nstr) - 1)

    first_half = int(''.join(reversed(nstr[:ndigits_halved + len(nstr) % 2])))
    second_half = int(nstr[-ndigits_halved:])
    return min(worst_case, first_half + second_half) + result_so_far


def solve(n):
    if n <= 20:
        return n

    nstr = str(n)
    result = get_counts_to_reach_digits(len(nstr))
    if DEBUG:
        print('To reach 10**%d: %s' % (len(nstr) -1, result))

    return solve_for_order(n, nstr, result)


if __name__ == '__main__':
    t = input()
    for i in range(t):
        task = read_task()
        result = solve(task)
        print_result(i + 1, result)
