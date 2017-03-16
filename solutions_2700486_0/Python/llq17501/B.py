#!/usr/bin/env python
#-*- coding:utf-8 -*-

import sys

ints = lambda f:map(int, next(f).split(' '))

def get_input(f = sys.stdin):
    T = int(next(f))
    for _ in range(T):
        data = ints(f)
        yield data

def f(N, X, Y):
    X = abs(X)
    k = (X + Y) / 2
    if (2 * k + 1) * (k + 1) <= N:
        return 1.0
    elif (2 * k - 1) * k >= N or (X== 0 and N < (2 * k + 1) * (k + 1)):
        return 0.0
    else:
        least = N - (2 * k - 1) * k
        if least < Y:
            return 0.0
        D = {(0, 0):1.}
        for s in range(1, least + 1):
            for i in range(s + 1):
                if i > 2 * k or s - i > 2 * k:
                    continue
                t = 0
                if i > 0:
                    t += D[(i-1, s-i)] / (2 if s-i < 2 * k else 1)
                if s-i > 0:
                    t += D[(i, s-i-1)] / (2 if i < 2 * k else 1)
                D[(i, s - i)] = t
        result = 0.0
        for i in range(Y + 1, min(least, 2 * k) + 1):
            if (s - i) <= 2 * k:
                result += D[(i, s - i)]
        return result




def main():
    for i, data in enumerate(get_input()):
        result = f(*data)
        print "Case #{0}: {1}".format(i + 1, result)

if __name__ == "__main__":
    main()
