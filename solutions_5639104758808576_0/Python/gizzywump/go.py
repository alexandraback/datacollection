#!/usr/bin/env python

import collections

import math
import re
import sys

#sys.setrecursionlimit(50)

INPUT = "tiny.txt"
INPUT = "A-small-attempt0.in"

def debug(*args):
    return
    sys.stderr.write(str(args) + "\n")

def do_trial(N, S):
    S = [int(x) for x in S]
    debug(S)
    total_standing = 0
    total_need = 0
    #import pdb; pdb.set_trace()
    for need, standing_round in enumerate(S):
        debug("round %d: %d standing" % (need, total_standing))
        if total_standing < need:
            debug("not enough standing in round %d, adding one here" % need)
            total_need += 1
            total_standing += 1
        total_standing += standing_round
    return total_need


f = file(INPUT)
T = int(f.readline()[:-1])
for i in range(T):
    N, S_list = f.readline().split()
    N = int(N)
    v = do_trial(N, S_list)
    print "Case #%d: %s" % (i+1, v)
