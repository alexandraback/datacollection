#!/usr/bin/python3

def solve():
    D = int(input())
    P = list(map(int, input().split()))
    res = max(P)
    for m in range(1, res):
        cnt = 0
        for x in P:
            cnt += (x-1) // m
        res = min(res, cnt + m)
    return res

if __name__ == "__main__":
    T = int(input())
    for t in range(T):
        print('Case #%d:' % (t+1), solve())
