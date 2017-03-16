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
import heapq


def info(message):
    #print "##", message
    sys.stdout.flush()
def warning(message):
    print >> sys.stderr, "warning: %s" % message
def error(s):
    sys.exit('error: ' + s)


# def splitinput(lines):
#     "default one line per part"
#     return [[line] for line in lines]

def splitinput(lines):
    i = 0
    while i < len(lines):
        n = int(lines[i])
        i += 1
        yield lines[i:i+n]
        i += n

def solve(n, part):
    levels = len(part)
    lstars = [ [ int(v) for v in line.split() ] for line in part ]
    lstars = [ l + [ False, False ] for l in lstars]
    #print part
    #print levels, lstars

    result = 0

    lstars_01 = [ ((l[0], -l[1]), l) for l in lstars ]
    lstars_02 = [ ((l[1], 0), l) for l in lstars ]
    lstars_12 = []
    heapq.heapify(lstars_01)
    heapq.heapify(lstars_02)

    #print '01:', lstars_01
    #print '02:', lstars_02

    st = 0
    result = 0

    while True:
        while lstars_02 and (lstars_02[0][1][2] or lstars_02[0][1][3]):
            info("pop02")
            heapq.heappop(lstars_02)
        if lstars_02 and lstars_02[0][0][0] <= st:
            t = heapq.heappop(lstars_02)
            info("do 02 %s" % [t])
            result += 1
            st += 2
            t[1][2] = True
            t[1][3] = True
            continue
        while lstars_12 and lstars_12[0][1][3]:
            info("pop12")
            heapq.heappop(lstars_12)
        if lstars_12 and lstars_12[0][0][0] <= st:
            t = heapq.heappop(lstars_12)
            info("do 12 %s" % [t])
            result += 1
            st += 1
            t[1][3] = True
            continue
        while lstars_01 and lstars_01[0][1][2]:
            info("pop01")
            heapq.heappop(lstars_01)
        if lstars_01 and lstars_01[0][0][0] <= st:
            t = heapq.heappop(lstars_01)
            info("do 01 %s" % [t])
            result += 1
            st += 1
            t[1][2] = True
            # push onto lstars_12!
            if t[1][1] > t[1][0]:
                item = ((t[1][1], 0), t[1])
                info("push 12 %s" % [item])
                heapq.heappush(lstars_12, item)
            else:
                info("not push 12 %s" % [item])
                t[1][3] = True
            continue
        if not lstars_01 and not lstars_12 and not lstars_02:
            break               # done

        # print 'XX'
        # print lstars_01
        # print lstars_12
        # print lstars_02
        # print result
        # print st

        result = "Too Bad"
        break

    print "Case #%d: %s" % (n, result)


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
