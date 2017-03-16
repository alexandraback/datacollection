import glob, pprint, pickle, os, time, sys
from copy import copy
from numpy import array, sin, cos, zeros
import itertools
import math
import numpy as np


def solve(p):
    num_q = p[0].count('?') + p[1].count('?')
    minimum = 10e9
    min_score = 1e9
    for digits in itertools.product('0123456789', repeat=num_q):
        digits = list(digits)
        sc0 = p[0]
        sc0 = ''.join([c if c!='?' else digits.pop() for c in sc0])
        sc0i = int(sc0)
        sc1 = p[1]
        sc1 = ''.join([c if c!='?' else digits.pop() for c in sc1])
        sc1i = int(sc1)
        abs_diff = abs(sc0i-sc1i)
        if abs_diff == minimum:
            if max(sc0, sc1)<min_score:
                min_score = max(sc0, sc1)
                minimum = abs_diff
                solution = (sc0,sc1)
        if abs_diff < minimum:
            min_score = max(sc0, sc1)
            minimum = abs_diff
            solution = (sc0,sc1)

    return solution



output = ""
TIC = time.time()
with open(sys.argv[1] if len(sys.argv) > 1 else "default.in") as f:
    def read_ints():
        return [int(x) for x in f.readline().strip().split(' ')]
    def read_frac():
        return [int(x) for x in f.readline().strip().split('/')]
    def read_strs():
        return [x for x in f.readline().strip().split(' ')]
    def read_floats():
        return [float(x) for x in f.readline().strip().split(' ')]
    def read_cakes():
        return [True if x=='+' else False for x in f.readline().strip()]

    (numquestions,) = read_ints()
    for questionindex in xrange(numquestions):

        ### calculate answer ###
        cakes = read_strs()
        answer = solve(cakes)

        ### output ###
        answer_str = "Case #{}: {}".format(questionindex+1, " ".join([str(a) for a in answer]))
        output += answer_str + '\n'
        print answer_str

ofile = open('output', 'w').write(output)
TOC = time.time()