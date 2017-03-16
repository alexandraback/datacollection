#!/usr/bin/env python3

# Google Code Jam 2012, Round 1B, Problem A: Safety In Numbers

cases = int(input())
for case in range(cases):
    inp = list(int(s) for s in input().split())
    N = inp[0]
    scores = inp[1:]
    total = sum(scores)
    minimum = 2*total/N
    p = list((minimum-sc)/total*100 if sc < minimum else 0 for sc in scores)
    size = sum(p)
    if abs(size-100) < 0.000000001:
        p = list(pi/size for pi in p)

    print("Case #{}:{}".format(case + 1, "".join(" {:.6f}".format(per) for per in p)))
