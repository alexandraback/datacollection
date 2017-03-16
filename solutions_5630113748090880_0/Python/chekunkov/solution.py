# -*- coding: utf-8 -*-
import sys
from collections import Counter


def solution(lines, N):
    c = Counter([n for l in lines for n in l])
    count = 0
    for k in sorted(c.keys()):
        if c[k] % 2 != 0:
            count += 1
            yield str(k)
    assert count == N


def main():
    T = int(next(sys.stdin))  # num test cases
    for case_num in range(1, T + 1):
        N = int(next(sys.stdin))
        lines = []
        for _ in range(2 * N - 1):
            line = next(sys.stdin).strip()
            lines.append(map(int, line.split(' ')))
        print "Case #%s:" % case_num, ' '.join(solution(lines, N))


if __name__ == '__main__':
    main()
