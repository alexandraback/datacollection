#!/usr/local/bin/python3

def solve(A, B):
    count = 0
    sA = str(A)
    sB = str(B)
    l = len(str(B))
    p = 10 ** (l - 1)
    for n in range(A, B):
        m = n
        while True:
            m = 10 * (m % p) + m // p
            if m == n:
                break
            if n < m <= B:
                count += 1
    return count

T = int(input())
for i in range(T):
    print("Case #{}: {}".format(i+1, solve(*(int(s) for s in input().split(' ')))))

