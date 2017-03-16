#!/usr/bin/python
# coding: utf-8

from __future__ import print_function

import sys
from sys import stdin
from itertools import product


def count(s, substr):
    cnt = 0
    start = 0
    while len(s) - start >= len(substr):
        f = s.find(substr, start)
        if f == -1:
            break
        else:
            cnt += 1
            start = f + 1
    return cnt


def solve(keys, word, S):
    max_cnt = 0
    sum_cnt = 0
    combs_num = 0
    for comb in product(keys, repeat=S):
        comb = "".join(comb)
        combs_num += 1
        cnt = count(comb, word)
        max_cnt = max(max_cnt, cnt)
        sum_cnt += cnt

    """
        print(comb, file=sys.stderr)
    print(max_cnt, sum_cnt, file=sys.stderr)
    print(file=sys.stderr)
    """

    if combs_num == 0:
        return 0.0
    else:
        return (combs_num * max_cnt - sum_cnt) / float(combs_num)


def main():
    T = int(next(stdin))
    for t in range(1, T+1):
        K, L, S = map(int, next(stdin).split())
        keys = next(stdin).strip()
        word = next(stdin).strip()
        print("Case #{}: {}".format(t, solve(keys, word, S)))


if __name__ == '__main__':
    main()

