#!/usr/bin/python3
# -*- coding: utf-8 -*-
# †
from itertools import count
import string, sys

def int2base(num, base, digits=string.digits+string.ascii_uppercase):
    is_negative = num < 0
    num = abs(num)
    if num == 0:
        return digits[0]
    s = ''
    while num:
        s += digits[num%base]
        num //= base
    s = s[::-1]
    if is_negative:
        s = '-' + s
    return s

base2int = lambda num, base: int(str(num), base)

conv = lambda r, n: int2base(r, 2).rjust(n, '0')

input()
n, m = map(int, input().split())

primes = [2, 3, 5, 7, 11]

print('Case #1:')
cnt = 0
for r in count(0):
    c = conv(r, n-2)
    s = '1' + c + '1'
    arr = [-1] * 9
    for base in range(2, 11):
        num = base2int(s, base)
        for p in primes:
            if num % p == 0:
                arr[base-2] = p
                break
    if any(v == -1 for v in arr):
        continue
    cnt += 1
    res = '{} {}'.format(s, ' '.join(map(str, arr)))
    print(res)
    if cnt >= m:
        break
