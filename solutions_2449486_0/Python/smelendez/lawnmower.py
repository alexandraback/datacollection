#!/usr/bin/python

import sys

def apply_mower(row, val):
    row = [min(x,val) for x in row]
    return row
def main():
    infile = file(sys.argv[1])

    ncases = int(infile.readline().strip())

    for case in xrange(1,ncases+1):
        nrows, ncols = [int(x) for x in infile.readline().strip().split(" ")]
        rows = []

        for i in xrange(nrows):
            rows.append([int(x) for x in infile.readline().strip().split(" ")])

        works = True
        for r in xrange(nrows):
            if not works:
                break
            for c in xrange(ncols):
                row = rows[r]
                col = [ro[c] for ro in rows]

                if apply_mower(row, row[c]) != row and apply_mower(col, row[c]) != col:
                    works = False
                    break

        if works:
            print "Case #%d: YES" % case
        else:
            print "Case #%d: NO" % case
main()


