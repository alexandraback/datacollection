#!/usr/bin/python

import sys


def solve(k, c, s):
    assert k == s
    return range(1, k+1)


def main():
    T = int(next(sys.stdin))
    for i in xrange(1, T+1):
        K, C, S = map(int, next(sys.stdin).split())
        print "Case #{}: {}".format(i, " ".join(str(x) for x in solve(K, C, S)))


if __name__ == '__main__':
    main()

