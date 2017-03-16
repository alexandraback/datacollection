import glob, pprint, pickle, os, time, sys
from copy import copy
from numpy import array, sin, cos, zeros
import itertools
import math
import numpy as np


def solve(p):
    B,M = p
    solution = np.zeros((B,B))

    if M==2**(B-2):
        return ("POSSIBLE",np.triu(np.ones((B,B)),1))
    # step 1: write M base 2
    l = []
    m=M
    while m>0:
        l = [m%2]+l
        m=m/2

    if len(l)+1>B-1:
        return ("IMPOSSIBLE",)
    # make that into a matrix:
    for i in xrange(0,B-1):
        solution[i,:i] = 1

    l = l[::-1]

    for idx, el in enumerate(l[:]):
        if el!=0:
            solution[-1,idx+1] = 1

    #print solution.T
    return ("POSSIBLE",solution.T)



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
        problem = read_ints()
        answer = solve(problem)

        ### output ###
        if len(answer)==1:
            answer_str = "Case #{}: {}".format(questionindex+1, " ".join([str(a) for a in answer]))
        else:
            answer,matrix = answer
            answer_str = "Case #{}: {}".format(questionindex+1, answer) + "\n"
            for l in matrix[:]:
                answer_str += "".join(["%d"%i for i in l]) + "\n"
            answer_str = answer_str.strip()

        output += answer_str + '\n'
        print answer_str

ofile = open('output', 'w').write(output)
TOC = time.time()