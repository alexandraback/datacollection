#!/usr/bin/env python
# -*- coding: utf-8 -*-
import sys

## ONLY FOR SMALL INPUTS!
def is_palin(x):
    return str(x) == str(x)[::-1]

UGUU = []

def preprocess():
    for i in xrange(1, 10**7):
        if is_palin(i) and is_palin(i*i):
            UGUU.append(i*i)
    print len(UGUU)

def process(num, fin, fout):
    a, b = [int(x) for x in fin.readline().split()]
    fout.write(str(sum(a <= x <= b for x in UGUU)))

if __name__ == '__main__':
    if len(sys.argv) != 3:
        print "Please indicate input and output"
        exit(0)
    preprocess()
    fin = open(sys.argv[1], 'r')
    fout = open(sys.argv[2], 'w')
    times = int(fin.readline())
    for i in xrange(times):
        fout.write("Case #%d: " % (i+1))
        process(i, fin, fout)
        fout.write("\n")
    fin.close()
    fout.close()
