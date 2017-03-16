#!/usr/bin/env python
# -*- coding: utf-8 -*-
import math
import numpy as np
import sys
import copy
import itertools as it
import re
import collections

def rint():
    return map(int, raw_input().split())

def rstr():
    return raw_input().split()

def rlist(*lfn):
    return  [f(a) for (f, a) in zip(lfn, raw_input().split())]

if __name__ == "__main__":
    testcases = input()
     
    for caseNr in xrange(testcases):
        [N] = rint()
        A = rint()

        print("Case #%i: %i" % (caseNr + 1, T))
#        print("Case #%i:" % (caseNr + 1))
