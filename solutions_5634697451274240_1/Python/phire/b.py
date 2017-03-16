#!/usr/bin/python2
# -*- coding: utf-8 -*-

import sys

def solve(s):
    last = s[0]
    r = 0
    for c in s:
        if c != last:
            r += 1
            last = c
    if last == '-':
        r += 1
    return r

def main():
    T = int(sys.stdin.readline())
    for t in xrange(1, T+1):
        s = sys.stdin.readline().strip()
        print "Case #%s: %s" % (t, solve(s))

if __name__ == '__main__':
    main()
