#!/usr/bin/env python
# -*- coding: utf-8 -*-
import sys

def process(num, fin, fout):
    table = []
    r, c = [int(x) for x in fin.readline().split()]
    for i in xrange(r):
        table.append([int(x) for x in fin.readline().split()])
    mrow = [max(row) for row in table]
    mcol = [max(row[j] for row in table) for j in xrange(c)]
    for i in xrange(r):
        for j in xrange(c):
            if table[i][j] < mrow[i] and table[i][j] < mcol[j]:
                fout.write('NO')
                return
    fout.write('YES')

if __name__ == '__main__':
    if len(sys.argv) != 3:
        print "Please indicate input and output"
        exit(0)
    fin = open(sys.argv[1], 'r')
    fout = open(sys.argv[2], 'w')
    times = int(fin.readline())
    for i in xrange(times):
        fout.write("Case #%d: " % (i+1))
        process(i, fin, fout)
        fout.write("\n")
    fin.close()
    fout.close()
