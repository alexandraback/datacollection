#!/usr/bin/env python3
# -*- coding: utf-8 -*-
# $File: solve.py
# $Date: Sat Apr 09 17:26:06 2016 +0800
# $Author: jiakai <jia.kai66@gmail.com>

def solve(seq):
    nseq = []
    for i in seq:
        if not (nseq and nseq[-1] == i):
            nseq.append(i)
    if nseq[-1] == '+':
        nseq.pop()
    return len(nseq)

def main():
    nr_case = int(input())
    for i in range(nr_case):
        print('Case #{}: {}'.format(i + 1, solve(input().strip())))

if __name__ == '__main__':
    main()
