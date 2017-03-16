#!/usr/bin/env python

# Half-baked multiprocessing can be had like so, assuming N on first input line
# and single-line output for every case.
#
# $ name=sample; p=8; N=$(head -1 ${name}.in); for n in $(seq 1 $N); do echo $n; done | xargs -P $p -n 1 ./sample.py -i ${name}.in -p | sort -t '#' -k2,2n > ${name}.out
#

## No, I don't code this sloppily in real life!  :-)


"""
"""

import optparse
import os
import os.path
import random
import re
import subprocess
import sys
import time


def info(message):
    print "##", message
    sys.stdout.flush()
def warning(message):
    print >> sys.stderr, "warning: %s" % message
def error(s):
    sys.exit('error: ' + s)


# def splitinput(lines):
#     "default one line per part"
#     return [[line] for line in lines]

def splitinput(lines):
    for n in xrange(len(lines)/2):
        yield lines[2*n:2*n+2]

def solve(n, part):
    a, b = [ int(v) for v in part[0].split() ]
    ps = [ float(v) for v in part[1].split() ]

    pps = [ 0 ] * (len(ps) + 1)
    prod = 1.0
    for i in xrange(a+1):
        pps[i] = prod
        if i < len(ps):
            prod *= ps[i]

    # give up immed
    best = float(1 + b + 1)

    if a == 0:
        best = b + 1
    elif b == 0:
        best = 1
    else:
        for d in xrange(0, a+1):
            strokes1 = 2*d + (b - a) + 1
            strokes2 = strokes1 + b + 1
            p1 = pps[a-d]
            p2 = 1.0 - p1
            e1 = p1 * strokes1
            e2 = p2 * strokes2
            e = e1 + e2
            best = min(best, e)
            #print 'cor', d, strokes1, p1, e1
            #print 'wro', d, strokes2, p2, e2

    #print a, b, ps, pps
    print "Case #%d: %s" % (n, float(best))


def main():
    parser = optparse.OptionParser(usage="usage: %prog [options] [<hostname>]",
                                   description=__doc__)
    parser.add_option("-p", action="store", type="int",
                      dest="part", help="part PART only (1-based!)")
    parser.add_option("-i", action="store",
                      dest="infile", help="input file (default stdin)")
    parser.add_option("-v", "--verbose", action="store_true",
                      dest="verbose", help="be verbose")
    parser.add_option("--string", action="store",
                      dest="astring", help="astring")
    parser.add_option("--int", action="store", type="int",
                      dest="anint", help="anint")
    (options, args) = parser.parse_args()

    if len(args) > 1:
        parser.print_help()
        sys.exit(1)

    infile = sys.stdin
    if options.infile:
        infile = open(options.infile)

    # assume input won't be huge
    lines = [ l.strip() for l in infile.readlines() ]
    N = int(lines[0])
    inputs = list(splitinput(lines[1:]))
    assert len(inputs) == N, ("bad input split %s %s" % (len(inputs), N))

    if options.part:
        solve(options.part, inputs[options.part-1])
    else:
        for p in xrange(1, N+1):
            solve(p, inputs[p-1])
            sys.stdout.flush()


if __name__ == '__main__':
    main()
