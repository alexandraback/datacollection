#!/usr/bin/python

import os
import sys
import math

fn = sys.argv[1]

fh = open(fn, "r")
T = int(fh.readline().strip())
cases = []

for i in range(T):
    case = {}
    [r, t] = map(int, fh.readline().strip().split())
    case["r"] = r
    case["t"] = t
    cases.append(case)

fh.close()

#print cases

def possible_with_j(t,r,j):
    return t >= (2*r-1+2*j)*j



def determine_case(case):
    r = case["r"]
    t = case["t"]
    j_init = int(math.sqrt(t))+1
    lower = 0
    upper = j_init
    while upper-lower>1:
        j = lower + (upper-lower)/2
        if possible_with_j(t,r,j):
            lower = j
        else:
            upper = j
    return str(lower)

fh_o = open("out.txt","w")
for i, case in enumerate(cases):
    print >> fh_o, "Case #"+str(i+1)+": "+ determine_case(case)


fh_o.close()

