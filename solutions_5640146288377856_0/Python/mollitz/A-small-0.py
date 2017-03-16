#!/usr/bin/env python
import sys
import ipdb

def calc(ifile):
    r,c,w = [int(v) for v in ifile.readline().split(' ')]
    finding =  (c/w)*r
    if c%w == 0:
        return finding+(w-1)
    else:
        return finding+w

if __name__ == "__main__":
    if len(sys.argv) > 1:
        ifile = open(sys.argv[1])
    else:
        ifile = sys.stdin
    if len(sys.argv) > 2:
        ofile = open(sys.argv[2])
    else:
        ofile = sys.stdout
    for i in range(int(ifile.readline())):
        ofile.write("Case #%i: %s\n" % (i+1, calc(ifile)))

