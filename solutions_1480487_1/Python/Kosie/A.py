#!/usr/bin/env python3

T = int(input())

def not_eliminated(idx, v):
    global s, N, X
    t = X-v
    for i in range(N):
        if i == idx:
            continue
        t -= max(0, s[idx]+v-s[i])
    return t < 0

def binsearch(l, h, f, i):
    ans = h
    while h-l > 1e-7:
        m = (l+h)/2

        if f(i, m*X):
            h = m
        else:
            l = m
    return h

for case in range(1, T+1):
    s = list(map(int, input().split()))[1:]
    N = len(s)
    X = sum(s)

    #print(s, N, X)
    #print(not_eliminated(0, X-1))

    ans = [0]*N
    ans = [binsearch(0, 1, not_eliminated, i) for i in range(N)]

    #print("Case #{}: {}".format(case, " ".join(str(a) for a in ans)))
    print("Case #{}: {}".format(case, " ".join("{:.8%}".format(a)[:-1] for a in ans)))
