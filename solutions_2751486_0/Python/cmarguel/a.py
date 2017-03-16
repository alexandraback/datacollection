#!/usr/bin/python

import sys

def readints(f):
    return [int(s) for s in f.readline().split()]

def readint(f):
    return int(f.readline())

def readmatrix(f, rows):
    matrix = []
    for i in xrange(rows):
        matrix += [readints(f)]
    return matrix

def simp(s):
    x = ""
    for c in s:
        if c in "aeiou":
            x += "0"
        else:
            x += "1"
    return x

def cons(c):
    return c == "1"

def solve(s, n):
    s = simp(s)
    l = len(s)
    x = 0
    v = 0
    prev = 0
    start = 0
    for i in xrange(l):
        c = s[i]
        if not cons(c):
            v += prev
            x = 0
        else:
            x += 1
            if x >= n:
                #print i, n, i-n+2
                v += (i-n+2)
                prev = (i-n+2)
            else:
                v += prev
        #print s[0:i+1], prev, v

    return v


def solvex(s, n):
    s = simp(s)
    l = len(s)
    x = 0
    v = 0
    prev = 0
    start = 0
    for i in xrange(len(s)):
        c = s[i]
        if cons(c):
            x += 1
        else:
            x = 0
        if x >= n:
            #print i, start, n, i-start-n+2
            v += (i-start-n+2)
            prev = i-start-n+2
        else:
            v += prev
        if not cons(c) and i-1 >= 0 and v > 0 and cons(s[i-1]):
            #print "b", i, n, i-n
            start = i-n
        print s[0:i+1], prev, v
    return v


if __name__ == "__main__":
    f = open(sys.argv[1], "r")
    numCases = readint(f)
    for i in xrange(numCases):
        s, n = f.readline().split()
        print "Case #%d: %d" % (i + 1, solve(s, int(n)))
