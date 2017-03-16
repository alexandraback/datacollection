#!/usr/bin/env python
# -*- coding: utf-8 -*-

import sys
readl = sys.stdin.readline

def read_case():
    case = [readl().strip() for i in range(4)]
    readl() # Skip empty line
    return case

def wins(case_wildcard, c):
    case = [e.replace('T', c) for e in case_wildcard]
    case_T = [''.join(case[i][j] for i in range(4)) for j in range(4)]
    diag0 = ''.join(case[i][i] for i in range(4))
    diag1 = ''.join(case[i][3-i] for i in range(4))

    return any(e==c*4 for e in case+case_T+[diag0, diag1])

n_cases = int(readl())
for i in range(1, n_cases+1):
    case = read_case()
    print 'Case #%d:'%i,
    if wins(case, 'X'): print 'X won'
    elif wins(case, 'O'): print 'O won'
    elif any(['.' in e for e in case]): print 'Game has not completed'
    else: print 'Draw'
