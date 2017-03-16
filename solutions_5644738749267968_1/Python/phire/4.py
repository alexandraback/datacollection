#!/usr/bin/python2
# -*- coding: utf-8 -*-

import sys

def parse_num(s):
    assert s[:2] == "0."
    return int(s[2:])

def deceit(naomi, ken):
    return len(naomi) - war(ken, naomi)

def war(naomi, ken):
    j = 0
    for i, n in enumerate(naomi):
        while j < len(ken) and n > ken[j]:
            j += 1
        if j < len(ken):
            j += 1
        else:
            return len(naomi) - i
    return 0

def main():
    T = int(sys.stdin.readline())
    for t in xrange(1, T+1):
        N = int(sys.stdin.readline())
        naomi = sorted(map(parse_num, sys.stdin.readline().split()))
        ken = sorted(map(parse_num, sys.stdin.readline().split()))
        print "Case #%d: %d %d" % (t, deceit(naomi, ken), war(naomi, ken))

if __name__ == '__main__':
    main()
