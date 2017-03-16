# Python 3.2

from common import *

# 0 = 0
# 1 = 1
# 2 = either 0 or 1

ways = [
        [
            [1, 0, 1],
            [1, 0, 1],
            [2, 0, 2]
        ],
        [
            [1, 0, 1],
            [0, 1, 1],
            [1, 1, 2]
        ],
        [
            [2, 0, 2],
            [1, 1, 2],
            [3, 1, 4]
        ]
    ]

digits = 32

def binary(n):
    b = []
    for i in range(digits):
        b.append(n % 2)
        n = n // 2

    return b

def decompose(n):
    b = binary(n)
    res = []

    for i in range(digits):
        if b[i] == 1:
            b2 = b[:]
            b2[i] = 0
            for j in range(i):
                b2[j] = 2
            res.append(b2)

    return res

def count(a, b, k):
    num = 1
    for i in range(digits):
        num *= ways[a[i]][b[i]][k[i]]
    return num

def main(casenum):
    a, b, k = readints()
    a_ = decompose(a)
    b_ = decompose(b)
    k_ = decompose(k)

    num = 0

    for a in a_:
        for b in b_:
            for k in k_:
                num += count(a, b, k)

    writeline('Case #{}: {}'.format(casenum, num))

run(main)
