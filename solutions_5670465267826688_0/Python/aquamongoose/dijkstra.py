#!/usr/bin/env python3

Q = ['1', 'i', 'j', 'k', '-1', '-i', '-j', '-k']
index = {Q[i] : i for i in range(len(Q))}
mult = [[0, 1, 2, 3, 4, 5, 6, 7],
        [1, 4, 3, 6, 5, 0, 7, 2],
        [2, 7, 4, 1, 6, 3, 0, 5],
        [3, 2, 5, 4, 7, 6, 1, 0],
        [4, 5, 6, 7, 0, 1, 2, 3],
        [5, 0, 7, 2, 1, 4, 3, 6],
        [6, 3, 0, 5, 2, 7, 4, 1],
        [7, 6, 1, 0, 3, 2, 5, 4]]

def transition(c, d):
    return Q[mult[index[c]][index[d]]]

def get_pos(L, X, S, want, rev=False):
    times = min(4, X)
    cur = '1'
    if rev:
        S = S[::-1]
    for i in range(times * L):
        if rev:
            cur = transition(S[i%L], cur)
        else:
            cur = transition(cur, S[i%L])
        if cur == want:
            return i
    return -1

def possible(L, X, S):
    cur = '1'
    for i in range(L * (X % 4)):
        cur = transition(cur, S[i%L])
    if cur != '-1':
        return False

    i_pos = get_pos(L, X, S, 'i')
    k_pos = get_pos(L, X, S, 'k', rev=True)

    return i_pos >= 0 and k_pos >= 0 and i_pos + k_pos + 2< L*X

T = int(input())
for test in range(T):
    L, X = map(int, input().split())
    S = input()
    print('Case #{}: {}'.format(test+1, "YES" if possible(L, X, S) else "NO"))
