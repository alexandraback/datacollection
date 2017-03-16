#!/usr/bin/env python
# -*- coding: utf-8 -*-
import numpy as np

def solver(word):

    S = ''
    for i, a in enumerate(word):
        if i==0:
            S = a
        else:
            if ord(a) >= ord(S[0]):
                S = a+S
            else:
                S = S+a
    return S

if __name__ == "__main__":

    testcases = input()
    for caseNr in xrange(1, testcases+1):
        str = raw_input()
        o = solver(str)
        print "Case #%d: %s" % (caseNr, o)