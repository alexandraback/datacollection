#!/usr/bin/python

import sys

def main():
    acceptable = [1,4,9,121,484]

    infile = file(sys.argv[1])

    nlines = int(infile.readline().strip())

    for i in xrange(1,nlines+1):
        bottom, top = [int(x) for x in infile.readline().strip().split(" ")]

        print "Case #%d: %d" % (i, len([x for x in acceptable if bottom <= x and x <= top]))

main()
