#!/usr/bin/env python3

import sys
from math import sqrt

N = int(sys.argv[1])
J = int(sys.argv[2])

LIMIT = 10**5

def find_proof(s, base):
    n = int(s, base)
    for v in range(2, min(int(sqrt(n)), LIMIT) + 1):
        if n % v == 0:
            return v
    return None

def search(low, high):
    res = []
    for n in range(0, 2**N):
        s = '{0:b}'.format(n)
        if len(s) != N or s[0] != '1' or s[-1] != '1':
            continue

        proof = []
        for base in range(2, 10+1):
            this = find_proof(s, base)
            if this is not None:
                proof.append(this)
            else:
                break
        if len(proof) == 9:
            res.append([n, proof])

        if len(res) >= J:
            break

    return res

res = []
block_size = 2000

for low in range(0, 2**N, block_size):
    high = min(low + block_size, 2**N)
    res.extend(search(low, high))
    if len(res) >= J:
        break


print('Case #1:')
for n, proof in res[:J]:
    print('{0:b} '.format(n) + ' '.join([str(_) for _ in proof]))
