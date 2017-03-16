#!/usr/bin/env python
#-*- coding:utf-8 -*-

import bisect

def g(P):
    m = P.pop(-1)
    if m == 1:
        return m
    a = m / 2
    b = m - a
    bisect.insort(P, a)
    bisect.insort(P, b)
    return min(m, 1 + g(P))

def f(P):
    P = sorted(P)
    i = 0
    result = None
    while True:
        m = P.pop(-1)
        if result is None or result > m + i:
            result = m + i
        if i > result:
            return result
        a = m / 2
        b = m - a
        bisect.insort(P, a)
        bisect.insort(P, b)
        i += 1
    return result

def main():
    in_f = "B-small-attempt0.in"
    out_f = "B.out"
    with open(in_f) as in_file, open(out_f, "w") as out_file:
        input_f = lambda :next(in_file)
        read_int = lambda :int(input_f())
        read_ints = lambda :map(int, input_f().split(' '))
        read_lines = lambda n:[input_f().strip() for i in range(n)]
        T = read_int()
        for i in range(T):
            D = read_int()
            P = read_ints()
            result = f(P)
            print "Case #{0}: {1}".format(i + 1, result)
            out_file.write("Case #{0}: {1}\n".format(i + 1, result))


if __name__ == "__main__":
    main()
