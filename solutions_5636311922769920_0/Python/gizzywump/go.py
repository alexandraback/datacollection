#!/usr/bin/env python

import collections

import math
import re
import sys


INPUT = "tiny"
#INPUT = "D-large.in"
INPUT = "D-small-attempt0.in"

def debug(*args):
    return
    sys.stderr.write(str(args) + "\n")

def iterate(t, K, C):
    v = t
    for i in range(C-1):
        v = v * K + t
    return v

def do_trial(K, C, S):
    r = []
    for t in range(S):
        r.append(iterate(t, K, C) + 1)
    return ' '.join(str(x) for x in r)

f = file(INPUT)
T = int(f.readline()[:-1])
for i in range(T):
    K, C, S = [int(x) for x in f.readline().split()]
    v = do_trial(K, C, S)
    print "Case #%d: %s" % (i+1, v)
