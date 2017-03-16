#!/usr/bin/env python
# -*- coding: UTF-8 -*-

from __future__ import division
from fileparser import FileParser
import numpy as np


def toarray(s=""):
    a = np.zeros(26)
    for c in s:
        a[ord(c)-ord("A")] += 1
    return a


def solve(s):
    mat = np.array([
        toarray(digit)
        for digit in ("ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE")
    ])
    b = toarray(s)
    inv = np.linalg.pinv(mat)
    x = b.dot(inv)

    num = [int(round(y)) for y in x]
    sol = ""

    for i, n in enumerate(num):
        sol += str(i) * n

    return sol


def main():
    inputfile = FileParser()
    T = inputfile.read_int()
    for test in range(1, T + 1):
        S = inputfile.read_string()

        result = solve(S)

        print "Case #{}: {}".format(test, result)


if __name__ == '__main__':
    main()
