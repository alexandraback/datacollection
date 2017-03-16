#!/usr/bin/env python
# -*- coding: utf-8 -*-

import sys
import math
import itertools

if __name__ == '__main__':
    if len(sys.argv)<2:
        print 'Syntax', sys.argv[0], 'fname'
        sys.exit(1)

    max_n = int(1e14**.5)
    max_n_digits = int(math.log(max_n, 10))
    fs = []

    for n_digits in range(1, max_n_digits+1):
        n_central = n_digits%2
        n_lateral = n_digits/2
        if n_central:
            for digits in itertools.product(*([range(10)]*(n_lateral+1))):
                candidate = digits+digits[:-1][::-1]
                if not candidate[0]: continue
                v = int(''.join([str(e) for e in candidate]))**2
                s_v = str(v)
                if s_v == s_v[::-1]:
                    fs.append(v)
        else:
            for digits in itertools.product(*([range(10)]*n_lateral)):
                candidate = digits+digits[::-1]
                if not candidate[0]: continue
                v = int(''.join([str(e) for e in candidate]))**2
                s_v = str(v)
                if s_v == s_v[::-1]:
                    fs.append(v)

    f = open(sys.argv[1])
    n_cases = int(f.readline().strip())

    for i in range(1, n_cases+1):
        i_fs = 0
        a, b = [int(e) for e in f.readline().strip().split()]

        fair_square = 0
        while fs[i_fs]<a: i_fs += 1
        while fs[i_fs]<=b:
            fair_square += 1
            i_fs += 1

        print 'Case #%d:'%i, fair_square
