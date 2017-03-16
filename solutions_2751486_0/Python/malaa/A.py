# -*- coding: utf-8 -*-
"""
Created on Wed Apr 10 21:58:25 2013

@author: malaa
"""

from copy import deepcopy
import numpy as np
import re

stop = False

c = set('bcdfghjklmnpqrstvwxyz')
v = set('aeiou')

def read_input(file_name):
    input = open(file_name).readlines()
    input = [i.strip() for i in input]
    print input

    T = int(input[0])
    cases = list()

    for t in xrange(T):
        inp = input[t+1].split(' ')
        case = {'string':inp[0], 'n':int(inp[1])}
        cases.append(case)
    return (T, cases)

def set_ones_zeros(s):
    out = list()
    for ch in s:
        if ch in c:
            out.append(1)
        else:
            out.append(0)
    return out

def find_runs(s, n):
    # take first diff
    dif = np.diff(np.r_[0, s], 1)
    # look for ones
    ones = np.nonzero(dif == 1)[0]

    # loop
    runs = np.array([])
    for o in ones:
        # look for first -1 to the right
        fmo = np.nonzero(dif[o+1:] == -1)[0] + o+1
        if fmo.size > 0:
            runlen = (fmo[0] - o + 1)
        else:
            runlen = (len(s) - o + 1)
        # check the index, it should be > n
        while runlen > n:
            runs = np.r_[runs, o]
            runlen -= 1
            o += 1

    return runs

def check_case(case):
    arr = set_ones_zeros(case['string'])
    # get runs of n consonants
    runs = find_runs(arr, case['n'])
    print runs

    # compute number of substrings
#    ss = set()
    num = 0
    for (i, r) in enumerate(runs):
        if i == 0: pre = r + 1
        else:      pre = r - runs[i-1]
#        if i < len(runs) - 1: suf = runs[i+1] - r
#        else:
        suf = len(arr) - (r + case['n']) + 1
#        num += 1
        num += pre * suf
        print "pre:", pre, "suf:", suf

#    if len(runs) > 1: num += 1
    return num

def check_cases(cases):
    out = list()
    for t in xrange(len(cases)):
        print "Case:", t
        case = cases[t]
        s = check_case(case)
        out.append("Case #%d: %d" % (t+1, s))

    return out


infile = 'A-small-attempt1.in' #'C-example.txt' # 'C-small-attempt1.in'

(T, cases) = read_input(infile)
print cases
out = check_cases(cases)
print out
#
open(infile + ".out", 'w').write("\n".join(out))

