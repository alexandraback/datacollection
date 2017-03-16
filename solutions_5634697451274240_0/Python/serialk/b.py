#!/usr/bin/python3

def answer(s):
    r = 0
    cur = s[0]
    for c in s:
        if c != cur:
            cur = c
            r += 1
    if cur == '-':
        r += 1
    return r


T = int(input())
for i in range(T):
    S = input()
    print('Case #{}: {}'.format(i + 1, answer(S)))
