# -*- coding: utf-8 -*-
from sys import stdin, stdout

stdin = open('A-large.in', 'r')
stdout = open('A-large.out', 'w')


def solve():
    R, C, W = [int(item) for item in stdin.readline().split()]
    cnt = C / W * R
    if C % W > 0:
        cnt += 1
    cnt += W - 1
    stdout.write('%d\n' % cnt)

T = int(stdin.readline())
for t in range(T):
    stdout.write('Case #%d: ' % (t+1))
    solve()