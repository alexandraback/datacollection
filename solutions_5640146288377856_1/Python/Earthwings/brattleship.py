#!/bin/env python

'''
Created on 10.05.2015

@author: Dennis Nienhüser <earthwings@gentoo.org>
'''

import sys
import math


def vectorize(line):
    items = line.strip().split(sep=' ')
    for index, item in enumerate(items):
        items[index] = int(item)
    return items


if __name__ == "__main__":
    inputFile = open(sys.argv[1], 'r')
    problems = int(inputFile.readline())
    for problemIndex in range(problems):
        problem = vectorize(inputFile.readline())
        r = problem[0]
        c = problem[1]
        l = problem[2]
        s = 0 if c % l == 0 else 1
        g = math.floor(c/l)*r + l-1 + s
        print ('Case #' + str(problemIndex+1) + ": " + str(g))
