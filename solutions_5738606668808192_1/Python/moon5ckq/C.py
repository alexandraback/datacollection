#! /usr/bin/env python
# -*- coding: utf-8 -*-
# vim:fenc=utf-8
#
# Copyright © 2016 mlckq <moon5ckq@gmail.com>
#
# Distributed under terms of the MIT license.

import math, random

def xn_mod_p2(x, n, p):
    res = 1
    n_bin = bin(n)[2:]
    for i in range(0, len(n_bin)):
        res = res**2 % p
        if n_bin[i] == '1':
            res = res * x % p
    return res

def miller_rabin_witness(a, p):
    if p == 1:
        return False
    if p == 2:
        return True
    n = p - 1
    t = int(math.floor(math.log(n, 2)))
    u = 1
    while t > 0:
        u = n / 2**t
        if n % 2**t == 0 and u % 2 == 1:
            break
        t = t - 1
    b1 = b2 = xn_mod_p2(a, u, p)
    for i in range(1, t + 1):
        b2 = b1**2 % p
        if b2 == 1 and b1 != 1 and b1 != (p - 1):
            return False
        b1 = b2
    if b1 != 1:
        return False
    return True

def prime_test_miller_rabin(p, k):
    while k > 0:
        a = random.randint(1, p - 1)
        if not miller_rabin_witness(a, p):
            return False
        k = k - 1
    return True

def random_a_jamcoin(n):
    return '1' + ''.join(map( lambda x: random.sample(['1', '0'], 1)[0], range(n - 2))) + '1'

def to_int(s, base):
    res = 0
    for ch in s:
        res *= base
        if ch == '1':
            res += 1
    return res

def print_result(jamcoin):
    ans = []
    for i in xrange(2, 11):
        num = to_int(jamcoin, i)
        j = 2
        while j < 10000:
            if num % j == 0:
                break
            j += 1
        if num % j != 0:
            return False
        ans.append(j)
    return jamcoin + ' ' + ' '.join(map(str,ans))

if __name__ == '__main__':
    n, j = 32, 500
    check = set()
    while True:
        jamcoin = random_a_jamcoin(n)

        isvalid = True
        for i in xrange(2, 11):
            num = to_int(jamcoin, i)
            if prime_test_miller_rabin(num, 20):
                isvalid = False
                break
        
        if isvalid and jamcoin not in check:
            res = print_result(jamcoin)
            if res == False:
                continue
            check.add(jamcoin)
            print res
            j -= 1
            if j == 0:
                break

    print len(check)
