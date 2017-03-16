#!/usr/bin/env python3

def good(start, S):
    standing = start
    for i in range(len(S)):
        if standing < i and S[i] > 0:
            return False
        standing += S[i]
    return True

T = int(input())
for test in range(T):
    _, S = input().split()
    S = [int(s) for s in S]
    for i in range(len(S)):
        if good(i, S):
            print('Case #{}: {}'.format(test+1, i))
            break
