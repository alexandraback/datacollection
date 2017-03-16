#!/usr/bin/env python3

def solve(k, c, s):
    if s**c < k:
        return "IMPOSSIBLE"
    res = []
    targets = list(range(1, k+1))
    #targets.reverse()

    while targets:
        sm = 0
        for i in range(0, c):
            pos = targets.pop() if targets else 1
            sm += k**i * (pos-1)
        res.append(str(sm+1))
    return ' '.join(res)


testcases = int(input())

for case_n in range(1, testcases+1):
    case_data = map(int, input().split())
    #case_data = input().split()
    print("Case #%i: %s" % (case_n, solve(*case_data)))
