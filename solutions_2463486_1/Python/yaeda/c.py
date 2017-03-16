#!/bin/python
# -*- coding: utf-8 -*-

import sys
import math
import itertools

def is_palindromes(num):
    str_num = str(num)
    return str_num == str_num[::-1]

def check_small(s, e):
    ret = 0
    ss = int(math.ceil(math.sqrt(s)))
    ee = int(math.floor(math.sqrt(e)))
    for i in range(ss, ee + 1):
        if is_palindromes(i) and is_palindromes(i * i):
            ret += 1
    return ret

def check_by_len(length, start, end):
    # range
    s = start if start is not None else 10 ** (length - 1)
    e = end if end is not None else 10 ** length
    ret = 0
    if length == 1:
        for i in range(1, 4):
            if s <= i and i < e:
                ret += 1
        return ret
    # len is not 1
    hl = int(math.ceil(length/2.0))
    for item in itertools.product(range(3), repeat=hl):
        item = [str(x) for x in list(item)]
        item = ''.join(item)
        if item[0] == '0': continue
        for i in range(length - len(item) - 1, -1, -1):
            item += item[i]
        n = int(item)
        if s <= n and e > n and is_palindromes(n) and is_palindromes(n * n):
            ret += 1
    return ret

def check_large(s, e):
    ret = 0
    ss = int(math.ceil(math.sqrt(s)))
    ee = int(math.floor(math.sqrt(e)))
    sl = len(str(ss))
    el = len(str(ee))
    for l in range(sl, el + 1):
       ret += check_by_len(l, ss, ee + 1)
    return ret

if __name__ == '__main__':
    lines = sys.stdin.readlines()
    n = int(lines[0][:-1])
    for i in range(0, n):
        s, e = [int (x) for x in lines[1 + i][:-1].split(' ')]
        result = check_large(s, e);
        print 'Case #%d: %d' % (i+1, result)
    # for i in range(0, 10000):
    #     result = check_large(1, 10 ** 14);
    #     print 'Case #%d: %d' % (i+1, result)
   # for i in range(0, 1000):
   #     result = check_large(1, 10 ** 100);
   #     print 'Case #%d: %d' % (i+1, result)
