#!/usr/local/bin/python3.5 -tt

import random
import sys


def check(n):
    for i in range(2, 10 ** 6 + 1):
        if n % i == 0:
            return i


if __name__ == '__main__':
    def _(f):
        for l in f:
            for i in l.split():
                yield int(i)

    g = _(sys.stdin)

    T, N, J = (next(g),
               next(g),
               next(g),
               )

    print("Case #1:")
                
    i, j = 0, 0

    while 1:
        s = bin(i)[2:]

        if len(s) > N - 2:
            raise

        while len(s) < N - 2:
            s = '0' + s

        s = '1%s1' % s

        a = []
        
        for b in range(2, 10 + 1):
            n = int(s, b)

            x = check(n)

            if not x:
                break

            a.append(x)

        if len(a) == 9:
            print('%s %s' % (s, ' '.join(str(i) for i in a)))

            j += 1

            if j == J:
                break
            
        i += 1
