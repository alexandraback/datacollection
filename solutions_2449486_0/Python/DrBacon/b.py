#!/usr/bin/python

import os
import sys

fn = sys.argv[1]

fh = open(fn, "r")
T = int(fh.readline().strip())
cases = []

for i in range(T):
    case = {}
    [N, M] = map(int, fh.readline().strip().split())
    case["N"] = N
    case["M"] = M
    case["L"] = []
    for j in range(N):
        case["L"].append(map(int, fh.readline().strip().split()))
    cases.append(case)

fh.close()


def determine_case(case):
    N = case["N"]
    M = case["M"]
    L = case["L"]
    max_ns = map(lambda n: max(L[n]), range(N))
    max_ms = map(lambda m: max(map(lambda n: L[n][m], range(N))), range(M))
    #return "%s %s" % (max_ns, max_ms)
    L_new = N*[M*[100]]
    #L_new = N*row_new
    counter = 0
    entries = sum(L, [])
    for n in range(N):
        for m in range(M):
            if entries[counter] != min([max_ns[n], max_ms[m]]):
                return "NO"
            counter +=1
    return "YES"




fh_o = open("out.txt","w")
for i, case in enumerate(cases):
    
    print >> fh_o, "Case #"+str(i+1)+": "+ determine_case(case)

fh_o.close()

