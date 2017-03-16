#!/usr/bin/env python
# -*- coding:utf-8 -*-

from math import sqrt
import sys

def readint(): return int(raw_input())
def readfloat(): return float(raw_input())
def readarray(N, foo):
        res = []
        for _ in xrange(N):
                res.append(foo())
        return res
def readlinearray(foo): return map(foo, raw_input().split())

def is_palindrome(n):
    n = str(n)
    return n == n[::-1]
    
def solve(A, B):
    ans = 0
    i = 0
    nn = palin_gen()
    while (i ** 2 < A): i = nn.next()
    while(i ** 2 <= B):
        if is_palindrome(i ** 2):
            ans += 1
        i = nn.next()
    return ans

    
def palin_gen():
    max_next_value = 10
    for v in xrange(1, 10):
        yield v
    init_left_part = 0
    left_part = init_left_part
    size = 2
    while True:
        if size % 2 == 0:
            while True:
                left_part += 1
                if left_part == max_next_value:
                    left_part = init_left_part
                    size += 1
                    break
                yield int(str(left_part) + str(left_part)[::-1])
        else:
            while True:
                left_part += 1
                if left_part == max_next_value:
                    init_left_part = max_next_value - 1
                    max_next_value *= 10
                    left_part = init_left_part
                    size += 1
                    break
                for i in xrange(10):
                    yield int(str(left_part) + str(i) + str(left_part)[::-1])
    
if __name__ == '__main__':
    C = readint()
    for c in xrange(1, C+1):
        A, B = readlinearray(int)
        ans = solve(A, B)
        print 'Case #%d: %s' % (c, ans)
