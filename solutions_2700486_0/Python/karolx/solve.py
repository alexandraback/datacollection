__author__ = 'karol'

import sys
import itertools


def newton(n, k):
    w = 1
    for i in range( 1, k+1 ):
        w = w * ( n - i + 1 ) / i
    return w


def find_level(n):
    for level in itertools.count(1, 2):
        req = (level * (level + 1)) / 2
        if req > n:
            return max(level - 2, 1)


def solve_single_case():
    N, X, Y = [int(x) for x in sys.stdin.readline().split()]
    # print "input", N, X, Y
    level = find_level(N)
    dist = abs(X) + abs(Y)
    if dist < level:
        return 1.0
    if dist > level + 2:
        return 0.0
    if Y > level:
        return 0.0
    used = (level * (level + 1)) / 2
    left_tries = N - used
    required = Y + 1
    if left_tries < required:
        return 0.0
    if left_tries > level + 1:
        always_filled = left_tries - level - 1
        n = left_tries - (always_filled * 2)
        k = required - always_filled
        if k < 1:
            return 1.0
    else:
        n = left_tries
        k = required
    # print "level", level, "left", left_tries, "req", required
    # print "n", n, "k", k
    bad = 0
    for i in range(k):
        bad += newton(n, i)
    comb = 2**n
    # print bad, comb
    bad_prob = float(bad) / comb
    return 1 - bad_prob


def main():
    T = int(sys.stdin.readline())
    for case in xrange(1, T + 1):
        solution = solve_single_case()
        print "Case #%d: %.9f" % (case, solution)

main()