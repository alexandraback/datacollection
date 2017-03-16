#!/usr/bin/python
import sys
import itertools
import os
import re
import string
import math

def binary(num, pre='', length=8, spacer=0):
    return '{0}{{:{1}>{2}}}'.format(pre, spacer, length).format(bin(num)[2:])

def solver(params):
    a = params['a']
    b = params['b']
    k = params['k']

    count = 0
    for i in xrange(a):
        for j in xrange(b):
            n = i & j
            if n < k:
                count += 1
    return count


def reader(in_file):
    parts = in_file.readline().strip().split(' ')
    a = int(parts[0])
    b = int(parts[1])
    k = int(parts[2])
    return {'a': a, 'b': b, 'k': k}


if __name__ == "__main__":
    from gcj import GCJ
    import os
    GCJ(reader, solver, os.getcwd(), "b").run()

