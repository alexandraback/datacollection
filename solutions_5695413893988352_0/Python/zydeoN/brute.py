#!/usr/bin/env python3

from numpy import float64   # so that float64(1)/0 == inf (avoid errors)
inf = float('inf')
read_ints = lambda : list(map(int, input().split()))

def rec(S, ans):
    if S == []:
        N = len(ans)
        sC = ans[:N//2]
        sJ = ans[N//2:]
        score = abs(int(sC) - int(sJ))
        return [(score, (sC, sJ))]

    if S[0] != '?':
        return rec(S[1:], ans+S[0])

    res = []
    for i in range(10):
        res.extend( rec(S[1:], ans+str(i)) )
    return res


def brute(sC, sJ):
    solutions = rec(list(sC+sJ), '')
    ans = min(solutions, key = lambda x: (x[0], int(x[1][0]), int(x[1][1])) )
    return ans[1][0] + ' ' + ans[1][1]

if __name__ == '__main__':
    T = int(input())
    for tc in range(1, T+1):
        sC, sJ = input().split()
        ans = brute(sC, sJ)
        print("Case #%d: %s" % (tc, ans))