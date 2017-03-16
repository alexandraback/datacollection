from collections import Counter

def solve(K, L, S, kb, targ):
    kb = Counter(kb)
    for ch in targ:
        if ch not in kb:
            return 0.0
    best = 0
    for k in range(1, L):
        if targ[-k:] == targ[:k]:
            best = k
    upper = (S - L) // (L - best) + 1
    expected = S - (L - 1)
    for ch in targ:
        expected *= kb[ch] / K
    return upper - expected

T = int(input())
for tc in range(1, T+1):
    K, L, S = map(int, input().split())
    kb = input()
    targ = input()
    print("Case #{}: {}".format(tc, solve(K, L, S, kb, targ)))
