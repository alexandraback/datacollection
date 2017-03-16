#!/usr/bin/python
# -*- coding: utf-8 -*-
import sys
import math

def check(s, n):
    count = 0
    for i in xrange(0, len(s)):
        if s[i] not in ['a', 'e', 'i', 'o', 'u']:
            count += 1
        else:
            if count >= n:
                return True
            count = 0
    return True if count >= n else False

if __name__ == "__main__":

    fin = open("A-small-0.in", "r")
    fout = open("A-small-0.out", "w")
    T = int(fin.readline())

    for k in xrange(0, T):
        s, n = fin.readline().split()
        s = str(s)
        n = int(n)
        n_value = 0

        for i in xrange(0, len(s)):
            for j in xrange(i+1, len(s)+1):
                if check(s[i:j], n):
                    n_value += 1

        fout.write("Case #%i: %i\n" % (k+1, n_value))
    
    fin.close()
    fout.close()

