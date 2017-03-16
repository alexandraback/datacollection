#!/usr/bin/env python
#-*- coding:utf-8 -*-

import math


def reverse(n):
    result = 0
    while n > 0:
        result = result * 10 + n % 10
        n = n / 10
    return result


def f(n):
    if n < 10:
        return n
    digits_count = int(math.log10(n)) + 1
    half = digits_count / 2
    t = 10 ** (digits_count - 1)
    if n / (10 ** (digits_count - half)) > 10 ** (half - 1):
        if n % 10 == 0:
            return f(n - 1) + 1
        x = n % (10 ** half)
        return f(reverse(n - x + 1)) + x
    else:
        return f(t - 1) + n - t + 1


def main():
    f_name = "A-large"
    in_f = "{0}.in".format(f_name)
    out_f = "{0}.out".format(f_name)
    with open(in_f) as in_file, open(out_f, "w") as out_file:
        input_f = lambda :next(in_file).strip()
        read_int = lambda :int(input_f())
        read_ints = lambda :map(int, input_f().split(' '))
        read_lines = lambda n:[input_f() for i in range(n)]
        T = read_int()
        for i in range(T):
            N = read_int()
            result = f(N)
            print "Case #{0}: {1}".format(i + 1, result)
            out_file.write("Case #{0}: {1}\n".format(i + 1, result))


if __name__ == "__main__":
    main()
