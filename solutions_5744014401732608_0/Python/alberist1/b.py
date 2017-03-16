#!/usr/bin/python3
# -*- coding: utf-8 -*-


def solve():
    b, m = map(int, input().split())
    if 2**(b-2) < m:
        return 'IMPOSSIBLE'
    m -= 1
    result = ['POSSIBLE']
    for i in range(b):
        line = ''
        for j in range(b):
            if (i == 0 and j == b-1) or (j > i and (j != b-1 or (m & (1<<(i-1))) != 0)):
                line += '1'
            else:
                line += '0'
        result.append(line)
    return '\n'.join(result)


if __name__ == '__main__':
    t = int(input())
    for i in range(t):
        print('Case #%d:' % (i+1), solve())
