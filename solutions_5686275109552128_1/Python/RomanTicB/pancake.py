#!/usr/bin/env python
# -*- coding: utf-8 -*-

def solve(_d, _p):
    D = int(_d)
    P = [int(i) for i in _p.split()]
    minutes = max(P)
    G = 2

    while G < minutes:
        minutes = min(minutes, sum([(x - 1) // G for x in P]) + G)
        G += 1

    return minutes

if __name__ == "__main__":
    testcases = input()

    for caseNr in xrange(1, testcases+1):
        _d = raw_input()
        _p = raw_input()
        print("Case #%i: %s" % (caseNr, solve(_d, _p)))