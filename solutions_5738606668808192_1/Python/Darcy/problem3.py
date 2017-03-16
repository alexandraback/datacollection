#!/usr/bin/env python
# encoding: utf-8
"""
problem3.py

Created by Darcy on 09/04/2016.
Copyright (c) 2016 Darcy. All rights reserved.
"""

import sys
import os
import time
import math


def nontrivial(x):
    for i in xrange(2, 100):
        if x % i == 0:
            return i
    return None

def main():
    for tc in range(input()):
        N, J = raw_input().split(' ')

        fat = '{0:0%sb}' % N
        print 'Case #%d:' % (tc+1,)

        k = 0
        for i in xrange(2**(int(N)-1), 2**int(N)):
            x = fat.format(i)
            # x = '100011'
            if x[0] == '0' or x[-1] == '0':
                continue
            # print x, int(x, 2), i
            divisors = []
            p = None
            for d in xrange(2, 11):
                z = int(x, d)
                p = nontrivial(z)
                if not p:
                    break
                divisors.append(p)
                # print x, z, d
            if not p or len(divisors) < 9:
                continue
            print x,

            for d in divisors:
                print d,
            print
            k += 1
            if k >= int(J):
                break
        # print N, J


if '__main__' == __name__:
    main()
