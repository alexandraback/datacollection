# -*- coding: utf-8 -*-
from sys import stdin, stdout

stdin = open('A-small-attempt0.in', 'r')
stdout = open('A-small-attempt0.out', 'w')


def solve():
    R, C, W = [int(item) for item in stdin.readline().split()]
    cnt = C / W
    if C % W > 0:
        cnt += 1
    cnt += W - 1
    stdout.write('%d\n' % cnt)

T = int(stdin.readline())
for t in range(T):
    stdout.write('Case #%d: ' % (t+1))
    solve()