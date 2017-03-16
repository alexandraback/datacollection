#!/usr/bin/env python2
# -*- coding: utf-8 -*-
# $File: solve.py
# $Date: Sat Apr 13 22:40:44 2013 +0800
# $Author: jiakai <jia.kai66@gmail.com>

def solve_case(nrow, ncol, mat):
    row_max = [max(r) for r in mat]
    col_max = [max(r[i] for r in mat) for i in range(ncol)]

    for i in range(nrow):
        for j in range(ncol):
            if mat[i][j] < row_max[i] and mat[i][j] < col_max[j]:
                return 'NO'

    return 'YES'

def main():
    nr_case = int(raw_input())
    for casenu in range(1, nr_case + 1):
        n, m = map(int, raw_input().split())
        mat = [map(int, raw_input().split()) for i in range(n)]
        print 'Case #{}:'.format(casenu), \
                solve_case(n, m, mat)


if __name__ == '__main__':
    main()
