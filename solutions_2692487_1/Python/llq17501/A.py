#!/usr/bin/env python
#-*- coding:utf-8 -*-

import sys

ints = lambda f:map(int, next(f).split(' '))

def get_input(f = sys.stdin):
    T = int(next(f))
    for _ in range(T):
        A, N = ints(f)
        M = ints(f)
        yield A, M

def f(A, M):
    if A == 1:
        return len(M)
    M.sort()
    lst = []
    k = 0
    for i, v in enumerate(M):
        if v >= A:
            lst.append(len(M) - i + k)
            while v >= A:
                A += (A - 1)
                k += 1
        A += v
    lst.append(k)
    return min(lst)

def main():
    for i, data in enumerate(get_input()):
        result = f(*data)
        print "Case #{0}: {1}".format(i + 1, result)

if __name__ == "__main__":
    main()
