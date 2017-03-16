#!/usr/bin/python3
# -*- coding: utf-8 -*-
# †
from collections import defaultdict, deque
from fractions import gcd
from itertools import count
from random import randrange
import string

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


def rabin_miller(n):
    if n < 2:
        return False
    if n != 2 and not n & 1:
        return False
    s = n - 1
    while not s & 1:
        s >>= 1
    for _ in range(20):
        a = randrange(n-1) + 1
        tmp = s
        mod = pow(a, tmp, n)
        while tmp != n-1 and mod != 1 and mod != n-1:
            mod = (mod * mod) % n
            tmp <<= 1
        if mod != n-1 and not tmp & 1:
            return False
    return True

def brent(n):
    if not n & 1:
        return 2
    x = randrange(0, n)
    c = randrange(1, n)
    m = randrange(1, n)
    y, r, q = x, 1, 1
    g, ys = 0, 0
    while g <= 1:
        x = y
        for _ in range(r):
            y = (y*y + c) % n
        k = 0
        while k < r and g <= 1:
            ys = y
            for _ in range(min(m, r-k)):
                y = (y*y + c) % n
                q = (q*abs(x-y)) % n
            g, k = gcd(q, n), k+m
        r <<= 1
    if g == n:
        while g <= 1:
            ys = (ys*ys + c) % n
            g = gcd(abs(x-ys), n)
    return g

# (ΦωΦ)＜nが1のときは空の辞書を返すことに注意!!
def factorize(n):
    que = deque()
    res = defaultdict(int)
    if n == 1:
        return res
    que.append(n)
    while que:
        l = que.pop()
        if rabin_miller(l):
            res[l] += 1
            continue
        d = brent(l)
        que.append(d)
        if d != l:
            que.append(l//d)
    return res


conv = lambda r, n: int2base(r, 2).rjust(n, '0')

input()
n, m = map(int, input().split())

print('Case #1:')
cnt = 0
for r in count(0):
    c = conv(r, n-2)
    s = '1' + c + '1'
    arr = [-1] * 9
    for base in range(2, 11):
        num = base2int(s, base)
        if rabin_miller(num):
            continue
        factored = factorize(num)
        k = list(filter(lambda v: v!=1 and v!=num, sorted(factored.keys())))[0]
        arr[base-2] = k
    if any(v == -1 for v in arr):
        continue
    cnt += 1
    res = '{} {}'.format(s, ' '.join(map(str, arr)))
    print(res)
    if cnt >= m:
        break
