#!/usr/bin/env python
#-*- coding:utf-8 -*-


MAP= [[0, 1, 2, 3], [1, 0, 3, 2], [2, 3, 0, 1], [3, 2, 1, 0]]
POS_MAP = [[True, True, True, True], [True, False, True, False], [True, False, False, True], [True, True, False, False]]

class Num(object):
    def __init__(self, i = 0, pos = True):
        self.i = i
        self.pos = pos

    def __mul__(self, N):
        pos = POS_MAP[self.i][N.i] ^ self.pos ^ N.pos
        i = MAP[self.i][N.i]
        return Num(i, pos)

    def __pow__(self, n):
        if n == 1:
            return self
        else:
            k = self ** (n / 2)
            if n % 2 == 1:
                return k * self
            else:
                return k

    def __eq__(self, N):
        return self.pos == N.pos and self.i == N.i

    def __str__(self):
        return "{0}{1}".format("" if self.pos else "-", ["1", "i", "j", "k"][self.i])


def f(X, S):
    m = {"i": Num(1), "j":Num(2), "k":Num(3)}
    n = Num()
    k = 0
    for i in range(min(X / 4, 3) * 4 + X % 4):
        for c in S:
            n = n * m[c]
            if k == 0 and n == Num(1):
                n = Num()
                k = 1
            elif k == 1 and n == Num(2):
                n = Num()
                k = 2

    if k == 2 and n == Num(3):
        return "YES"
    else:
        return "NO"


def main():
    in_f = "C-large.in"
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
