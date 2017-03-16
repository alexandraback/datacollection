#!/usr/bin/python2
# -*- coding: utf8 -*-
# Google Code Jam 2016 - 1C - Problem B - Mateusz Kurek

from itertools import combinations, tee


def get_next(n):
    for l2 in range(1, n):
        yield from combinations(range(2, n), l2)


def pairwise(iterable):
    a, b = tee(iterable)
    next(b, None)
    return zip(a, b)


def pm(matrix):
    r = [' '.join(map(str, row)) for row in matrix]
    print('\n'.join(r))


def solve():
    b, m = map(int, input().split())
    matrix = []
    for i in range(b):
        matrix.append([0] * b)
    matrix[0][b - 1] = 1
    m -= 1
    for pl in get_next(b):
        if m == 0:
            break
        s = (1,) + pl + (b,)
        # print(s)
        for x, y in pairwise(s):
            # print(x, y)
            matrix[x - 1][y - 1] = 1
        m -= 1
        # pm(matrix)
    if m == 0:
        r = ['POSSIBLE'] + [''.join(map(str, row)) for row in matrix]
    else:
        r = ['IMPOSSIBLE']
    return '\n'.join(r)


def main():
    t = int(input())
    for i in range(1, t + 1):
        result = solve()
        print('Case #{}: {}'.format(i, result))

if __name__ == '__main__':
    main()
