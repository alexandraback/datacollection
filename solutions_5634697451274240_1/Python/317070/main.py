import glob, pprint, pickle, os, time, sys
from copy import copy
from numpy import array, sin, cos, zeros
import itertools
import math
import numpy as np


def solve(cakes):
    groups = 1
    last_val = True
    for cake in cakes[::-1]:
        if cake!=last_val:
            groups+=1
        last_val = cake

    return (groups-1,)


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
        cakes = read_cakes()
        answer = solve(cakes)

        ### output ###
        answer_str = "Case #{}: {}".format(questionindex+1, " ".join([str(a) for a in answer]))
        output += answer_str + '\n'
        print answer_str

ofile = open('output', 'w').write(output)
TOC = time.time()