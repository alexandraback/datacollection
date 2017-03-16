#!/usr/bin/env python
import sys
import ipdb

def calc(ifile):
    out = 0
    c,d,v = [int(x) for x in ifile.readline().replace('\n','').split(' ')]
    ds = [int(x) for x in ifile.readline().replace('\n','').split(' ')]
    if ds[0] != 1:
        ds.insert(0, 1)
        out += 1
    possible = 0
    for sd in ds:
        while (sd-1) > possible:
            out += 1
            possible += ((possible+1)*c)
            if possible >= v:
                return out

        possible += (sd*c)
        if possible >= v:
            return out

    while possible < v:
        out += 1
        possible += ((possible+1)*c)
    return out



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

