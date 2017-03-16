import glob, pprint, pickle, os, time, sys
from copy import copy
from numpy import array, sin, cos
import numpy as np
import itertools
import math


def solve(p):
    l = [False]*10
    x = 0
    for i in xrange(1000001):
        x = x+p
        for decimal in str(x):
            l[int(decimal)] = True
            if sum(l)==10:
                return (x,)
    return ("INSOMNIA",)


output = ""
TIC = time.time()
with open(sys.argv[1] if len(sys.argv) > 1 else "default.in") as f:
    def read_ints():
        return [int(x) for x in f.readline().strip().split(' ')]
    def read_frac():
        return [int(x) for x in f.readline().strip().split('/')]
    def read_strs():
        return [x for x in f.readline().strip().split(' ')]
    def read_chrs():
        return [x for x in f.readline().strip()]
    def read_floats():
        return [float(x) for x in f.readline().strip().split(' ')]

    (numquestions,) = read_ints()
    for questionindex in xrange(numquestions):

        ### calculate answer ###
        (p,) = read_ints()
        answer = solve(p)

        ### output ###
        answer_str = "Case #{}: {}".format(questionindex+1, " ".join([str(a) for a in answer]))
        output += answer_str + '\n'
        print answer_str

ofile = open('output', 'w').write(output)
TOC = time.time()