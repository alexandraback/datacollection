import sys

def solve(S):
    if not S:
        return 0

    k = max(S.iterkeys())
    if k % 2:
        return 1 + solve({k-1: v for k, v in S.items() if k > 1})

    c = S[k]
    if k/2 not in S:
        S[k/2] = 0
    S[k/2] += 2*S[k]
    del S[k]

    return min(k, c + solve(S))

sys.setrecursionlimit(200000)
T = int(raw_input())
for x in xrange(1, T+1):
    D = int(raw_input())
    P = map(int, raw_input().split())
    print "Case #{}: {}".format(x, solve({e: P.count(e) for e in set(P)}))
