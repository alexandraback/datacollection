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
    [E, R, N] = map(int, fh.readline().strip().split())
    case["E"] = E
    case["R"] = R
    case["N"] = N
    vs = map(int, fh.readline().strip().split())
    case["vs"] = vs
    cases.append(case)

fh.close()

#print cases


def determine_case(case):
    E = case["E"]
    R = case["R"]
    N = case["N"]
    vs = case["vs"]
    max_use  = [E for i in range(N)]
    min_repo = [0 for i in range(N)]
    results  = [-1 for i in range(N)]
    act_es = sorted(list(set(vs)))[::-1]
    for act_e in act_es:
        indices = map(lambda x: x[0], filter(lambda (i,v): v==act_e, enumerate(vs)))
        for loc in indices[::-1]:
            #print act_e, loc, E, R, N, vs
            results[loc] = max_use[loc]-min_repo[loc]
            if loc < N-1:
                max_use[loc+1] = R+max_use[loc]-results[loc]
            for i in range(loc+2,N):
                new = min([max_use[i], max_use[i-1]+R])
                if new == max_use[i]:
                    break
                max_use[i] = new
            if loc - 1 >= 0:
                min_repo[loc-1] = max([results[loc] - R + min_repo[loc], min_repo[loc-1], 0])
            for i in range(loc-1)[::-1]:
                new = max([min_repo[i+1]-R, min_repo[i], 0])
                if new == min_repo[i]:
                    break
                min_repo[i] = new 
            #print results
            #print max_use
            #print min_repo
    if -1 in results:
        print resutls
    return str(sum(map(lambda i: results[i]*vs[i], range(N))))

fh_o = open("out2.txt","w")
#cases = [cases[8]]
for i, case in enumerate(cases):
    print >> fh_o, "Case #"+str(i+1)+": "+ determine_case(case)


fh_o.close()

