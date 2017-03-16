#! /usr/bin/env python

import sys
fin = open(sys.argv[1], "r")
fout = open("p3.out", "w")

T = int(fin.readline())

table = {'1' : {'1' : (1, '1'), 'i': (1, 'i'), 'j' : (1, 'j'), 'k': (1, 'k')},
         'i' : {'1' : (1, 'i'), 'i': (-1, '1'), 'j' : (1, 'k'), 'k': (-1, 'j')},
         'j' : {'1' : (1, 'j'), 'i': (-1, 'k'), 'j' : (-1, '1'), 'k': (1, 'i')},
         'k' : {'1' : (1, 'k'), 'i': (1, 'j'), 'j' : (-1, 'i'), 'k': (-1, '1')}}

def mult(x, y):
    ret = (x[0] * y[0] * table[x[1]][y[1]][0], table[x[1]][y[1]][1])
    return ret

for i in xrange(T):
    L, X = map(int, fin.readline().split())
    if X > 16:
        X = (X % 4) + 16
    s = zip([1 for j in xrange(L)], list(fin.readline().strip()))
    first, second, third = (1, '1'), (1, '1'), (1, '1')
    for j in xrange(X):
        for y in s:
            if first != (1, 'i'):
                first = mult(first, y)
            elif second != (1, 'j'):
                second = mult(second, y)
            else:
                third = mult(third, y)
    if first != (1, 'i') or second != (1, 'j') or third != (1, 'k'):
        ans = "No"
    else:
        ans = "Yes"
    fout.write("Case #" + str(i+1) + ": " + ans + "\n")
