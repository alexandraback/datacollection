#!/usr/bin/python2
# -*- coding: utf-8 -*-

import sys
import os

def solve(a, x):
    good = True
    for i in xrange(4):
        if a[i][i] != x and a[i][i] != 'T':
            good = False
    if good:
        return True

    good = True
    for i in xrange(4):
        if a[i][3-i] != x and a[i][3-i] != 'T':
            good = False
    if good:
        return True

    for i in xrange(4):
        good = True
        for j in xrange(4):
            if a[i][j] != x and a[i][j] != 'T':
                good = False
        if good:
            return True

    for i in xrange(4):
        good = True
        for j in xrange(4):
            if a[j][i] != x and a[j][i] != 'T':
                good = False
        if good:
            return True

    return False

def main():
    n = int(sys.stdin.readline())
    for i in xrange(1, n+1):
        print "Case #" + str(i) + ":",
        a = ["", "", "", ""]
        for j in xrange(4):
            a[j] = sys.stdin.readline().strip()
        sys.stdin.readline()
        if solve(a, 'X'):
            print "X won"
            continue
        if solve(a, 'O'):
            print "O won"
            continue
        not_over = any('.' in x for x in a)
        if not_over:
            print "Game has not completed"
        else:
            print "Draw"

if __name__ == '__main__':
    main()
