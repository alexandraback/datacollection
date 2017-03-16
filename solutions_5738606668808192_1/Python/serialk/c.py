#!/usr/bin/python3

from math import sqrt
from itertools import count, islice
import sys

def first_factor(n):
    for i in islice(count(2), min(int(sqrt(n) - 1), 1000)):
        if n % i == 0:
            return i
    return None

def answer(n, j):
    cur = int('1' + '0' * (n - 2) + '1', 2)
    done = 0
    while done < j:
        sc = bin(cur)[2:]
        lfac = []
        for base in range(2, 11):
            fac = first_factor(int(sc, base))
            if fac is not None:
                lfac.append(str(fac))
            else:
                break
        else:
            yield (sc, lfac)
            done += 1
            print(done, file=sys.stderr)
        cur += 2


T = int(input())
for i in range(T):
    n, j = list(map(int, input().split()))
    print('Case #{}:'.format(i + 1))
    for k, l in answer(n, j):
        print(k, ' '.join(l))
