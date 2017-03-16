#!/usr/bin/env python2
# -*-*- encoding: utf-8 -*-*-
# Created: Fri, 12 Apr 2013 22:47:10 -0300

"""
Problem C - Fair and Square
Google Code Jam - Qualification Round 2013
"""
__author__ = "Julio Batista Silva"
__copyright__ = ""
__license__ = "GPL"
__version__ = "1.0"


import itertools
import fileinput
import pickle
from bisect import bisect_left, bisect_right


def eh_palin(x):
    if str(x) == str(x)[::-1]:
        return True
    else:
        return False


def gera_lista():
    fair_square = [1, 4, 9]
    for k in range(2, 15):
        palindromos = [sum([n*(10**i)
                        for i, n in enumerate(
                            ([x]+list(y)+[z]+list(y)[::-1]+[x]) if k % 2
                            else ([x]+list(y)+list(y)[::-1]+[x]))])
                    for x in range(1, 3)
                    for y in itertools.product(range(3), repeat=k / 2 - 1)
                    for z in (range(3) if k % 2 else (None,))]
        for p in palindromos:
            p2 = p*p
            if eh_palin(p2):
                fair_square.append(p2)

    with open('fair_sqr.pickle', 'wb') as f:
        pickle.dump(fair_square, f)

    return fair_square


def main():
    #fs = gera_lista()
    with open('fair_sqr.pickle', 'rb') as f:
        fs = pickle.load(f)
    #print "fs = {}".format(fs)
    lines = iter(fileinput.input())
    next(lines)
    caso = 0
    for line in lines: 
        caso += 1
        A, B = line.split()
        L = bisect_left(fs, int(A))
        R = bisect_right(fs, int(B))
        #print "A = {}, B = {}, L = {}, R = {}".format(A, B, L, R)
        print "Case #{}: {}".format(caso, R - L)


if __name__ == "__main__":
    main()
    #gera_lista()
