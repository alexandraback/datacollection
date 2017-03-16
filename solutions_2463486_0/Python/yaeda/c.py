#!/bin/python
# -*- coding: utf-8 -*-

import sys
import math

def is_palindromes(num):
    str_num = str(num)
    return str_num == str_num[::-1]

def check(s, e):
    ret = 0
    ss = int(math.ceil(math.sqrt(s)))
    ee = int(math.floor(math.sqrt(e)))
    for i in range(ss, ee + 1):
        if is_palindromes(i) and is_palindromes(i * i):
            ret += 1
    return ret

if __name__ == '__main__':
    lines = sys.stdin.readlines()
    n = int(lines[0][:-1])
    for i in range(0, n):
        s, e = [int (x) for x in lines[1 + i][:-1].split(' ')]
        result = check(s, e);
        print 'Case #%d: %d' % (i+1, result)
#    for i in range(0, 10000):
#        result = check(1, 10 ** 14);
#        print 'Case #%d: %d' % (i+1, result)
