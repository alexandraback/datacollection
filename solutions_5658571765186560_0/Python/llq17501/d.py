#!/usr/bin/env python
#-*- coding:utf-8 -*-



def f(X, R, C):
    if R * C % X != 0:
        return "RICHARD"
    if X <= 2:
        return "GABRIEL"
    if X >= 2:
        if min(R, C) <= X / 2:
            return "RICHARD"
        else:
            return "GABRIEL"

def main():
    in_f = "D-small-attempt0.in"
    out_f = "D.out"
    with open(in_f) as in_file, open(out_f, "w") as out_file:
        input_f = lambda :next(in_file).strip()
        read_int = lambda :int(input_f())
        read_ints = lambda :map(int, input_f().split(' '))
        read_lines = lambda n:[input_f() for i in range(n)]
        T = read_int()
        for i in range(T):
            X, R, C = read_ints()
            result = f(X, R, C)
            print "Case #{0}: {1}".format(i + 1, result)
            out_file.write("Case #{0}: {1}\n".format(i + 1, result))


if __name__ == "__main__":
    main()
