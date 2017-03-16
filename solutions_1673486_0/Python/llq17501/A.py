#!/usr/bin/env python
#-*- coding:utf-8 -*-

read_ints = lambda :map(int, raw_input().split(' '))
read_floats = lambda :map(float, raw_input().split(' '))
read_lines = lambda n:[raw_input().strip() for i in range(n)]
DEBUG = False

def debug(*args, **kwargs):
    if DEBUG:
        for i, v in enumerate(args):
            print i, v
        for k, v in kwargs.iteritems():
            print k, v


def f(A, B, P):
    debug(B = B, P = P)
    m = B + 2
    for i in range(A):
        right = reduce(lambda x, y:x*y, P[:i + 1])
        t = B - A + (A - i - 1) * 2 + 1
        tmp = t * right + (t + B + 1) * (1 - right)
        if tmp < m:
            m = tmp
    return "%.6f" % m

def main():
    T = int(raw_input())
    for i in range(T):
        A, B = read_ints()
        P = read_floats()
        result = f(A, B, P)
        print "Case #{0}: {1}".format(i + 1, result)


if __name__ == "__main__":
    main()
