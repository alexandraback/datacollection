#!/usr/bin/env python2

def match(pattern, number):
    l = len(pattern)
    sn = str(number).zfill(l)

    for i in xrange(l):
        if pattern[i] != sn[i] and pattern[i] != '?':
            return False
    return True

def solve(C, J):
    l = len(C)

    mindiff = 999999
    minc = 99999
    minj = 99999

    for c in xrange(10**l):
        for j in xrange(10**l):
            if match(C, c) and match(J, j):
                df = abs(c - j)
                if df < mindiff:
                    mindiff = df
                    minc = c
                    minj = j
                elif df == mindiff:
                    if c < minc:
                        minc = c
                        minj = j
                    elif c == minc:
                        if j < minj:
                            minj = j
    return "%s %s" % (str(minc).zfill(l), str(minj).zfill(l))

T = int(raw_input())
for i in xrange(1, T+1):
    C, J = raw_input().strip().split()
    print "Case #%s: %s" % (i, solve(C, J))
