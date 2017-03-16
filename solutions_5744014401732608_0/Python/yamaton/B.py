"""
Google Code Jam
2016 Round 1C

Problem B.
    :author: yamaton
    :date: 2016-05-08
"""

import itertools as it
import functools
import operator
import collections
import math
import sys


def seq2matrix(seqs, B):
    res = [[0 for _ in range(B)] for _ in range(B)]
    for seq in seqs:
        for i, j in zip(seq, seq[1:]):
            res[i-1][j-1] = 1
    return res


def solve(B, M):
    tf = (M <= 2**(B-2))
    if not tf:
        return None
    sequences = []
    for i in range(B-1, -1, -1):
        choices = it.combinations(range(2, B), i)
        seqs = [([1] + list(choice) + [B]) for choice in choices]
        sequences += seqs

    return seq2matrix(sequences[:M], B)


def pp(*args, **kwargs):
    print(*args, file=sys.stderr, **kwargs)


def main():
    for _tc in range(1, int(input())+1):
        pp('\n--------- case #%d -------' % _tc)
        print("Case #%d: " % _tc, end='')
        B, M = [int(s) for s in input().strip().split()]

        xss = solve(B, M)
        pp()
        pp('(B, M) =', (B, M))
        if xss is None:
            print('IMPOSSIBLE')
        else:
            print('POSSIBLE')
            for xs in xss:
                print(*xs, sep='')

            pp()
            for xs in xss:
                pp(*xs, sep='')


if __name__ == '__main__':
    main()
