#!/usr/bin/python2
# -*- coding: utf-8 -*-

import sys

def solve(s):
    ret = s[0]
    for c in s[1:]:
        if ord(c) >= ord(ret[0]):
            ret = c + ret
        else:
            ret += c
    return ret

def main():
    T = int(sys.stdin.readline())
    for t in xrange(1, T+1):
        print "Case #%d: %s" % (t, solve(sys.stdin.readline().strip()))

if __name__ == '__main__':
    main()
