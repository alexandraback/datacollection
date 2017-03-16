#!/usr/bin/env python

import sys


def print_result(result, i):
    sys.stdout.write("Case #%s: %s\n" % (i, result))


def readline():
    return sys.stdin.readline().rstrip('\n')


def splitline(f):
    return map(f, readline().split())


def count_unique(xs, ys, rxs, rys):
    if not len(rxs):
        return len(xs)

    if (not rxs[0] in xs + rxs[1:]) or (not rys[0] in ys + rys[1:]):
        return count_unique(xs + [rxs[0]], ys + [rys[0]], rxs[1:], rys[1:])

    l1 = count_unique(xs + [rxs[0]], ys + [rys[0]], rxs[1:], rys[1:])
    l2 = count_unique(xs, ys, rxs[1:], rys[1:])
    return min(l1, l2)


def solve():
    N = splitline(int)[0]
    words = [splitline(str) for _ in range(N)]
    unique = count_unique([], [], [w[0] for w in words], [w[1] for w in words])
    return len(words) - unique


def main():
    for i in range(int(readline())):
        print_result(solve(), i + 1)


if __name__ == '__main__':
    main()
