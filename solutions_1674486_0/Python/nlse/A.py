#!/usr/bin/python

import sys
import re
import math
import fractions
import numpy

def find_inher(inher, x):
    if inher[x-1] == []:
        return [[]]
    r = []
    for i in inher[x-1]:
        sf = find_inher(inher, i)
        for s in sf:
            r.append([i] + s)
    return r

def compare(x1, x2):
    index = 0
    while index < min(len(x1), len(x2)) and x1[index] == x2[index]:
        index += 1
    for x in x1[index:]:
        if x in x2:
            return True
    return False

def find_dup(vec):
    xv = vec.pop()
    while len(vec) > 0:
        for v in vec:
            if compare(xv, v):
                return True
        xv = vec.pop()
    return False

f = open(sys.argv[1],'r')
num = int(f.readline())
for z in range(num):
    n = int(f.readline().strip())
    inher = []
    for i in range(n):
        x = [int(x) for x in f.readline().split()]
        inher.append(x[1:])
    #print n, inher
    found = False
    for i in range(1,n+1):
        ret = find_inher(inher,i)
        #print ret
        if find_dup(ret):
            found = True
            break
    if found:
        print 'Case #{}: Yes'.format(z+1)
    else:
        print 'Case #{}: No'.format(z+1)
    sys.stdout.flush()
