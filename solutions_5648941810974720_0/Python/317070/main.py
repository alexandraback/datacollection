import glob, pprint, pickle, os, time, sys
from copy import copy
from numpy import array, sin, cos
import numpy as np
import itertools
import math


def solve(p):
    res = ""
    while "Z" in p:
        res += "0"
        for l in "ZERO":
            p=p.replace(l,'',1)
    while "W" in p:
        res += "2"
        for l in "TWO":
            p=p.replace(l,'',1)
    while "U" in p:
        res += "4"
        for l in "FOUR":
            p=p.replace(l,'',1)
    while "X" in p:
        res += "6"
        for l in "SIX":
            p=p.replace(l,'',1)
    while "O" in p:
        res += "1"
        for l in "ONE":
            p=p.replace(l,'',1)
    while "F" in p:
        res += "5"
        for l in "FIVE":
            p=p.replace(l,'',1)
    while "S" in p:
        res += "7"
        for l in "SEVEN":
            p=p.replace(l,'',1)
    while "G" in p:
        res += "8"
        for l in "EIGHT":
            p=p.replace(l,'',1)
    while "H" in p:
        res += "3"
        for l in "THREE":
            p=p.replace(l,'',1)
    while "I" in p:
        res += "9"
        for l in "NINE":
            p=p.replace(l,'',1)
    assert p==""
    res = ''.join([ch for ch in sorted(res.replace(' ',''))]).replace(' ','')
    return (res,)


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
        (st,) = read_strs()
        answer = solve(st)

        ### output ###
        answer_str = "Case #{}: {}".format(questionindex+1, " ".join([str(a) for a in answer]))
        output += answer_str + '\n'
        print answer_str

ofile = open('output', 'w').write(output)
TOC = time.time()