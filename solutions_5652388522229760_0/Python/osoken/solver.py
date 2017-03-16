# coding: UTF-8

import sys


def solve(x):
    m = 1
    n = m * int(x)
    mem = set((n,))
    digits = set(str(n))
    while len(digits) < 10:
        m += 1
        n = m * int(x)
        if n in mem:
            return 'INSOMNIA'
        mem.add(n)
        digits = digits.union(set(str(n)))
    return str(n)


def test(f, t):
    for x in range(f, t):
        print str(x) + ': ' + solve(x)


if __name__ == '__main__':
    problemCounts = int(sys.stdin.readline())
    for cn, prob in enumerate(sys.stdin.readlines()):
        sys.stdout.write('Case #%d: %s\n' % ((cn+1), solve(prob)))
