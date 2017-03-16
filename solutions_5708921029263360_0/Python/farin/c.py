#!/usr/bin/env python3

from collections import defaultdict

def solve(J, P, S, K):
    jp = defaultdict(int)
    js = defaultdict(int)
    ps = defaultdict(int)
    jps = defaultdict(int)
    sol = 0
    rows = []
    for k in range(3*K+1):
        for j in range(J):
            for p in range(P):
                for s in range(S):
                    jpsK = "{}.{}.{}".format(j+1, p+1, s+1)
                    jpK = "{}.{}".format(j+1, p+1)
                    jsK = "{}.{}".format(j+1, s+1)
                    psK = "{}.{}".format(p+1, s+1)
                    if jps[jpsK]:
                        continue
                    #print("{}-{}-{} @\n{}\n{}\n{}".format(j+1, p+1, s+1, jp, js, ps))
                    if jp[jpK] == K:
                        break
                    if js[jsK] == K:
                        continue
                    if ps[psK] == K:
                        continue
                    if jp[jpK] + js[jsK] + ps[psK] > k:
                        continue
                    jp[jpK] += 1
                    js[jsK] += 1
                    ps[psK] += 1
                    jps[jpsK] += 1
                    sol += 1
                    rows.append("{} {} {}".format(j+1, p+1, s+1))
    return "{}\n{}".format(sol, "\n".join(rows))

testcases = int(input())

for case_n in range(1, testcases+1):
    case_data = map(int, input().split())
    #case_data = input().split()
    print("Case #%i: %s" % (case_n, solve(*case_data)))
