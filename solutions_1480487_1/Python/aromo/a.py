#!/usr/bin/python
""" template.py input-file > output-file"""

import sys
from numpy import *

def input_words():
    line = IN.readline()
    return line.strip().split()

def input_ints():
    return map(int, input_words())

def input_floats():
    return map(float, input_words())


def fill_until(a):
    x = sum(a)
    for i in range(len(a))[::-1]:
        y = a.copy()
        y[:i] = y[i]
        if sum(y) < 2*x:
            return i+1

def solve_one():
    """ XXX the real code comes here """
    line = input_ints()
    N = line[0]
    a_orig = array(line[1:]) * 1.
    a = a_orig.copy()
    a.sort()
    j = fill_until(a)
    x = sum(a)
    x0 = sum(a[:j])
    target_score = (x + x0)/float(j)
    
    result = 100. * (target_score - a_orig) / x
    result[result<0.] = 0
    
    r2 = map(lambda x: "%.6f" % (x,), result)

    return " ".join(r2)


if __name__ == "__main__":
    assert(len(sys.argv) == 2)
    IN = open(sys.argv[1])

    T = input_ints()[0]
    
    for i in range(T):
        print "Case #%d:" % (i+1,), solve_one()


