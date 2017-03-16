#!/usr/bin/env python
# encoding: utf-8
"""
problem2.py

Created by Darcy on 09/04/2016.
Copyright (c) 2016 Darcy. All rights reserved.
"""


def main():
    for tc in range(input()):
        pancakes = raw_input()

        i = pancakes.rfind('-')
        # print tc, pancakes, i
        t = 0
        while i >= 0:
            t += 1
            pancakes = pancakes[:i]
            cakes = []
            for pan in pancakes:
                if pan == '-':
                    cakes.append('+')
                if pan == '+':
                    cakes.append('-')
            pancakes = ''.join(cakes)
            i = pancakes.rfind('-')
            # print pancakes
        print 'Case #%d: %d' % (tc+1, t)


if '__main__' == __name__:
    main()
