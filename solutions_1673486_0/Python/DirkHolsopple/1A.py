#!/usr/bin/env python3
import sys
import math
import decimal

def give_up(A, B):
    return B+2

def optimal_backspace(A, B, p):
    wrong_cost = A+B+1+B+1
    right_cost = A+B+1
    p_total = decimal.Decimal(1)
    min_cost = A+B+1
    for prob in p:
        expected = right_cost*p_total + wrong_cost*(1-p_total)
        if expected < min_cost:
            min_cost = expected
        right_cost -= 2
        wrong_cost -= 2
        p_total *= prob
    expected = right_cost*p_total + wrong_cost*(1-p_total)
    if expected < min_cost:
        min_cost = expected
    return min_cost

def optimal_expected(A, B, p):
    return min(give_up(A,B), optimal_backspace(A,B,p))

with open(sys.argv[1], 'r') as f:
    T = int(f.readline())
    i = 0
    while i < T:
        A, B = map(int,f.readline().split())
        p = map(decimal.Decimal,f.readline().split())
        print("Case #%d: %.6f" % (i+1, optimal_expected(A, B, p)))
        i += 1
