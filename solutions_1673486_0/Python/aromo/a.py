#!/usr/bin/python
""" template.py < input-file """

import numpy as np

def raw_input_words():
    return raw_input().strip().split()

def raw_input_ints():
    return map(int, raw_input_words())

def raw_input_floats():
    return map(float, raw_input_words())

def product(l):
    if len(l) == 0:
        return 1
    else:
        return l[0] * product(l[1:])

def solve_one():
    A, B = raw_input_ints()
    p = raw_input_floats()

    outcomes = [B+2] # retype straight away

    for k in range(A): # k = number deleted
        outcome = B - A + 2 * k + 1 + (B + 1) * (1 - product(p[:A-k]))
        outcomes.append(outcome)

    m = np.array(outcomes).min()

    return m


if __name__ == "__main__":
    T = int(raw_input())
    for i in range(T):
        print "Case #%d:" % (i+1,), solve_one()

