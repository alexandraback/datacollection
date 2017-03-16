#!/usr/bin/env python3
import collections

T = int(input())
for t in range(1, T+1):
    ans = ''
    S = input()
    c = collections.Counter(S)
    for mark, word, addw in zip(['Z', 'X', 'G', 'W'], ['ZERO', 'SIX', 'EIGHT', 'TWO'], ['0', '6', '8', '2']):
        while c[mark] > 0:
            for w in word:
                c[w] -= 1
            ans += addw

    # three
    while c['H'] > 0:
        for w in 'THREE':
            c[w] -= 1
        ans += '3'
    while c['S'] > 0:
        for w in 'SEVEN':
            c[w] -= 1
        ans += '7'
    while c['R'] > 0:
        for w in 'FOUR':
            c[w] -= 1
        ans += '4'
    while c['V'] > 0:
        for w in 'FIVE':
            c[w] -= 1
        ans += '5'
    while c['O'] > 0:
        for w in 'ONE':
            c[w] -= 1
        ans += '1'
    while c['N'] > 0:
        for w in 'NINE':
            c[w] -= 1
        ans += '9'
    ans = "".join(sorted(ans))
    print("Case #{}: {}".format(t, ans))
