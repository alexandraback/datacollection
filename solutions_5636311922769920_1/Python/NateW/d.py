#!/usr/bin/env python

import sys


def contributors(k, c, i):
    result = set()
    for j in xrange(c, 0, -1):
        result.add(i % k)
        i /= k
    return result


def combine(tiles, k):
    i = 0
    for t in sorted(tiles):
        i = (i * k) + t
    return i


def solve(k, c, s):
    if k > (s * c):
        return "IMPOSSIBLE"

    tests = []
    tiles = range(k)
    step = c
    while tiles:
        chunk = tiles[:step]
        tiles = tiles[step:]
        tests.append(combine(chunk, k) + 1)

    return " ".join([str(t) for t in tests])


def main():
    assert contributors(3, 2, 0) == set([0])
    assert contributors(3, 2, 1) == set([0, 1])
    assert contributors(3, 2, 2) == set([0, 2])
    assert contributors(3, 2, 7) == set([1, 2])
    assert contributors(3, 2, 8) == set([2])
    assert combine([0, 1], 3) == 1
    assert combine([0, 2], 3) == 2
    assert combine([1, 2], 3) == 5

    lines = sys.stdin.readlines()
    tests = int(lines[0])
    for i in xrange(tests):
        k, c, s = [int(j) for j in lines[i + 1].split()]
        print "Case #%d: %s" % (i + 1, solve(k, c, s))


if __name__ == "__main__":
    main()
