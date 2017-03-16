#!/usr/bin/python

import os
import sys

fn = sys.argv[1]

fh = open(fn, "r")
T = int(fh.readline().strip())
cases = []
for i in range(T):
    case = map(int, fh.readline().strip().split(" "))
    ps   = map(float, fh.readline().strip().split(" "))
    cases += [(case,ps)]

fh.close()

fh_o = open("out.txt","w")
for i in range(T):
    (case,ps) = cases[i]
    A = case[0]
    B = case[1]
    p_complete = 1.0
    for p in ps:
        p_complete *= p
    v_cor = [1.0]
    v_inc = [0.0]
    for i_p in range(len(ps)):
        p = ps[i_p]
        v_cor += [v_cor[-1]*p]
        v_inc += [v_inc[-1]+v_cor[-2]*(1-p)]
    e_fin = p_complete * (B-A+1) + (1-p_complete) * (B-A+1+B+1)
    e_ent = (B+2)
    e_bs = []
    for j in range(A):
        e_b = v_cor[-j-1] * (j + j +B-A+1) + v_inc[-j-1] * (j + j +B-A+1 + B+1)
        e_bs += [e_b]
    print >> fh_o, "Case #"+str(i+1)+": "+str(min([e_fin, e_ent]+e_bs))

fh_o.close()
