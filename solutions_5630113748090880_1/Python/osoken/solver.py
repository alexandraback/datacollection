# coding: UTF-8

import sys


def solve(l):
    cnt = {}
    for r in l:
        for x in r:
            if x not in cnt:
                cnt[x] = 0
            cnt[x] += 1
    res = []
    for k, v in cnt.items():
        if v % 2 != 0:
            res.append(k)
    res.sort()
    return ' '.join(map(str, res))


if __name__ == '__main__':
    problemCounts = int(sys.stdin.readline())
    for cn in range(problemCounts):
        problemSize = int(sys.stdin.readline())
        l = []
        for sz in range(2*problemSize - 1):
            l.append(map(int, sys.stdin.readline().strip().split(' ')))
        sys.stdout.write('Case #%d: %s\n' % ((cn+1), solve(l)))
