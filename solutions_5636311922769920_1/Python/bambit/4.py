#!/usr/local/bin/python

import sys
from itertools import groupby

def convert_to_base10(l, base):
    answer = 0
    for element in l:
        answer *= base
        answer += element

    return answer+1

def solve(t):
    K, C, S = map(int, sys.stdin.readline().rstrip().split())

    checks = []
    for next in range((K-1)//C +1):
        check = range(next*C, min(next*C+C,K))
        if not check:
            continue

        checks.append(convert_to_base10(check, K))

    answer = 'IMPOSSIBLE' if len(checks) > S else ' '.join(map(str, checks)) 
    print 'Case #{}: {}'.format(t, answer)

if __name__=="__main__":
    T = int(sys.stdin.readline())
    for i in range(1, T+1):
        solve(i)
