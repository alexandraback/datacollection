#!/usr/bin/python3
from itertools import chain, repeat

# 0 ->  1
# 1 -> -1
# 2 ->  i
# 3 -> -i
# 4 ->  j
# 5 -> -j
# 6 ->  k
# 7 -> -k

mp = {'i': 2, 'j': 4, 'k': 6, '-1': 1, '1': 0}

mul = [
    [
        0, #  1 *  1
        1, #  1 * -1
        2, #  1 *  i
        3, #  1 * -i
        4, #  1 *  j
        5, #  1 * -j
        6, #  1 *  k
        7, #  1 * -k
    ],
    [
        1, # -1 *  1
        0, # -1 * -1
        3, # -1 *  i
        2, # -1 * -i
        5, # -1 *  j
        4, # -1 * -j
        7, # -1 *  k
        6, # -1 * -k
    ],
    [
        2, #  i *  1
        3, #  i * -1
        1, #  i *  i
        0, #  i * -i
        6, #  i *  j
        7, #  i * -j
        5, #  i *  k
        4, #  i * -k
    ],
    [
        3, # -i *  1
        2, # -i * -1
        0, # -i *  i
        1, # -i * -i
        7, # -i *  j
        6, # -i * -j
        4, # -i *  k
        5, # -i * -k
    ],
    [
        4, #  j *  1
        5, #  j * -1
        7, #  j *  i
        6, #  j * -i
        1, #  j *  j
        0, #  j * -j
        2, #  j *  k
        3, #  j * -k
    ],
    [
        5, # -j *  1
        4, # -j * -1
        6, # -j *  i
        7, # -j * -i
        0, # -j *  j
        1, # -j * -j
        3, # -j *  k
        2, # -j * -k
    ],
    [
        6, #  k *  1
        7, #  k * -1
        4, #  k *  i
        5, #  k * -i
        3, #  k *  j
        2, #  k * -j
        1, #  k *  k
        0, #  k * -k
    ],
    [
        7, # -k *  1
        6, # -k * -1
        5, # -k *  i
        4, # -k * -i
        2, # -k *  j
        3, # -k * -j
        0, # -k *  k
        1, # -k * -k
    ],
]

def solve():
    L, X = map(int, input().split())
    S = input()
    rs = mp['1']
    for x in S:
        rs = mul[rs][mp[x]]
    s = mp['1']
    for _ in range(X%4):
        s = mul[s][rs]
    if s != mp['-1'] or L*X < 3:
        return "NO"
    p = mp['1']
    i1 = L*X
    for i, x in enumerate(chain.from_iterable(repeat(S, min(X, 4)))):
        p = mul[p][mp[x]]
        if p == mp['i']:
            i1 = i
            break
    p = mp['1']
    i2 = -1
    for i, x in enumerate(chain.from_iterable(repeat(''.join(reversed(S)), min(X, 4)))):
        p = mul[mp[x]][p]
        if p == mp['k']:
            i2 = L*X-i-1
            break
    if i1 < i2:
        return "YES"
    return "NO"

if __name__ == "__main__":
    T = int(input())
    for t in range(T):
        print('Case #%d:' % (t+1), solve())
