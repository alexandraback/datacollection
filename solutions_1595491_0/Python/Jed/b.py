#!/usr/bin/env python2
# -*- coding: utf-8 -*-
# $File: b.py
# $Date: Sat Apr 14 11:21:55 2012 +0800
# $Author: jiakai <jia.kai66@gmail.com>

SCORE_MIN = 0
SCORE_MAX = 10


def solve_case(nsurp, req_score, tot_score):
    fcur = [0] * (nsurp + 1)

    surp_min = max(0, req_score - 2) * 2 + req_score
    nosurp_min = max(0, req_score - 1) * 2 + req_score
    for cur_tot in tot_score:
        fprev = fcur
        fcur = list()

        surp = cur_tot >= surp_min
        nosurp = cur_tot >= nosurp_min

        for i in range(nsurp + 1):
            if i:
                fcur.append(max(fprev[i - 1] + surp, fprev[i] + nosurp))
            else:
                fcur.append(fprev[0] + nosurp)

    return fcur[nsurp]

if __name__ == '__main__':
    ncase = int(raw_input())

    for casenu in range(1, ncase + 1):
        print 'Case #{0}:'.format(casenu), 

        data = [int(i) for i in raw_input().split()]
        [n, s, p] = data[:3]
        print solve_case(s, p, data[3:])

