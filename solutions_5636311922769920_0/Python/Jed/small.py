#!/usr/bin/env python3
# -*- coding: utf-8 -*-
# $File: small.py
# $Date: Sat Apr 09 21:05:15 2016 +0800
# $Author: jiakai <jia.kai66@gmail.com>

def solve(K, C, S):
    assert S == K
    return ' '.join(map(str, range(1, K + 1)))


def main():
    nr_case = int(input())
    for i in range(nr_case):
        print('Case #{}: {}'.format(i + 1, solve(*map(int, input().split()))))

if __name__ == '__main__':
    main()
