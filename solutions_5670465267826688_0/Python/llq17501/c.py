#!/usr/bin/env python
#-*- coding:utf-8 -*-

def change_status(status, c):
    neg, s = status
    if c == 'i':
        if s in (1, 2):
            neg = - neg
        s = [1, 0, 3, 2][s]
    elif c == 'j':
        if s in (2, 3):
            neg = -neg
        s = [2, 3, 0, 1][s]
    else:
        if s in (1, 3):
            neg = - neg
        s = [3, 2, 1, 0][s]

    return neg, s


def f(X, S):
    init_status = (1, 0)
    status = init_status
    k = 0
    for i in range(X):
        for c in S:
            status = change_status(status, c)
            if k == 0 and status == (1, 1):
                status = init_status
                k = 1
            elif k == 1 and status == (1, 2):
                status = init_status
                k = 2

    if k == 2 and status == (1, 3):
        return "YES"
    else:
        return "NO"

def main():
    in_f = "C-small-attempt0.in"
    out_f = "C.out"
    with open(in_f) as in_file, open(out_f, "w") as out_file:
        input_f = lambda :next(in_file).strip()
        read_int = lambda :int(input_f())
        read_ints = lambda :map(int, input_f().split(' '))
        read_lines = lambda n:[input_f().strip() for i in range(n)]
        T = read_int()
        for i in range(T):
            L, X = read_ints()
            S = input_f()
            result = f(X, S)
            print "Case #{0}: {1}".format(i + 1, result)
            out_file.write("Case #{0}: {1}\n".format(i + 1, result))


if __name__ == "__main__":
    main()
