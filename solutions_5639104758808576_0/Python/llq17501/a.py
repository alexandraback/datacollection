#!/usr/bin/env python
#-*- coding:utf-8 -*-



def f(s_max, digits):
    digits = map(int, digits)
    s = 0
    k = 0
    for i, d in zip(range(1, s_max + 1), digits):
        k += d
        if i > k:
            s += i - k
            k = i
    return s

def main():
    in_f = "A-small-attempt0.in"
    out_f = "A.out"
    with open(in_f) as in_file, open(out_f, "w") as out_file:
        input_f = lambda :next(in_file)
        read_int = lambda :int(input_f())
        read_ints = lambda :map(int, input_f().split(' '))
        read_lines = lambda n:[input_f().strip() for i in range(n)]
        T = read_int()
        for i in range(T):
            s_max, digits = input_f().strip().split(' ')
            result = f(int(s_max), digits)
            print "Case #{0}: {1}".format(i + 1, result)
            out_file.write("Case #{0}: {1}\n".format(i + 1, result))


if __name__ == "__main__":
    main()
