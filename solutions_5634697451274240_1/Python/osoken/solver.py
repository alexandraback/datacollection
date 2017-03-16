# coding: UTF-8

import sys


def count_diff(seq):
    res = 0
    for i in range(len(seq)-1):
        if seq[i] != seq[i+1]:
            res += 1
    return res


def solve(seq):
    return count_diff(seq) + int(seq[-1] == '-')

if __name__ == '__main__':
    problemCounts = int(sys.stdin.readline())
    for cn, prob in enumerate(sys.stdin.readlines()):
        sys.stdout.write('Case #%d: %s\n' % ((cn+1), solve(prob.strip())))
