#!/usr/bin/env python3

def solve(s):
    r = [s[0]]
    for c in s[1:]:
        #print(r[0], c, r)
        if r[0] > c:
            r.append(c)
        else:
            r.insert(0, c)
    return ''.join(r)


testcases = int(input())

for case_n in range(1, testcases+1):
    #case_data = map(int, input().split())
    case_data = input().split()
    print("Case #%i: %s" % (case_n, solve(*case_data)))
