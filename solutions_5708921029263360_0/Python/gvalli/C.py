#! /#!/usr/bin/env python
# -*- coding: utf-8 -*-

import sys

fh = open(sys.argv[1], 'r')
T = int(fh.readline())  # number of test cases
for t in range(T):
    # jackets, pants, shirts, number 2 comb to jail
    J, P, S, K = [int(v) for v in fh.readline().split()]
    res = list()
    comb_jp = dict()
    comb_js = dict()
    comb_ps = dict()
    for j in range(J):
        for p in range(P):
            for s in range(S):
                c = ' '.join(str(v) for v in [j + 1, p + 1, s + 1])
                jp = ''.join(str(v) for v in [j + 1, p + 1])
                js = ''.join(str(v) for v in [j + 1, s + 1])
                ps = ''.join(str(v) for v in [p + 1, s + 1])
                # one passes limit
                add = True
                for i in range(3):
                    cur = [jp, js, ps][i]
                    dat = [comb_jp, comb_js, comb_ps][i]
                    if (cur in dat) and (dat[cur] >= K):
                        add = False
                # do the addition
                if add:
                    res.append(c)
                    for i in range(3):
                        cur = [jp, js, ps][i]
                        dat = [comb_jp, comb_js, comb_ps][i]
                        if cur in dat:
                            dat[cur] += 1
                        else:
                            dat[cur] = 1
                # print comb_jp, comb_js, comb_ps
    res = '\n'.join([str(len(res))] + res)
    print('Case #{:d}: {}'.format(t + 1, res))
