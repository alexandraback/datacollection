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

mp = {'i': 2, 'j': 4, 'k': 6}

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
    s = 0
    m2 = m3 = 0
    for i, x in enumerate(chain.from_iterable(repeat(S, X)), 1):
        k = mp[x]
        sn = mul[s][k]
        m2n = m3n = 0
        if s == mp['i']:
            m2n |= 1<<k
        if m2 & (1<<mp['j']):
            m3n |= 1<<k
        for j in range(8):
            if m2 & (1<<j):
                m2n |= 1<<mul[j][k]
            if m3 & (1<<j):
                m3n |= 1<<mul[j][k]
        s, m2, m3 = sn, m2n, m3n
    if m3 & (1<<mp['k']):
        return 'YES'
    return 'NO'

if __name__ == "__main__":
    T = int(input())
    for t in range(T):
        print('Case #%d:' % (t+1), solve())
