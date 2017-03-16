#!/usr/bin/env python
# -*- coding: utf-8 -*-



def solve(f):
    N, *s = map(int, next(f).split())
    x = X = sum(s)
    S = (X*2)/N

    tmp = [(S-i)/X*100 for i in s]

    while any(i<0 for i in tmp):
        Z = [i for i in tmp if i<0]
        z=sum(Z)
        tmp = [i+z/(N-len(Z)) if i>0 else 0 for i in tmp]

    print(sum(tmp))
    return ' '.join("{:.6f}".format(i) for i in tmp)


with open("A-large.in") as IN:
    with open("A-large.out", 'w') as OUT:
        T = int(next(IN))

        for t in range(1, T+1):
            print("Case #{}: {}".format(t, solve(IN)), file=OUT)
