#!/usr/bin/env python3

def solve(A, B, K):
    return sum(1 for a in range(A) for b in range(B) if a & b < K)
    
tests = int(input())
for test in range(tests):
    A, B, K = map(int, input().split())
    result = solve(A, B, K)
    print("Case #{}: {}".format(1+test, result))
