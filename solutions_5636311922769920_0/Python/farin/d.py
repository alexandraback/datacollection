#!/usr/bin/env python3

def solve(k, c, s):
    res = []
    for pos in range(1, k+1):
        sm = 0
        for i in range(0, c):
            sm += k**i
        r = sm * (pos-1)
        res.append(str(r+1))
    return ' '.join(res)


testcases = int(input())

for case_n in range(1, testcases+1):
    case_data = map(int, input().split())
    #case_data = input().split()
    print("Case #%i: %s" % (case_n, solve(*case_data)))
