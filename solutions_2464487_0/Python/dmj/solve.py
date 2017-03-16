#!/usr/bin/env python

import sys
import logging

def solve(r, t):
    c = 0
    while True:
        u = (2*r + 1)
        
        if t < u:
            return c
        t -= u
        r += 2
        c += 1

def main(lines, output):
    T = int(lines.next())
    for case in xrange(1,T+1):
        r, t = map(int, lines.next().split())
        result = solve(r, t)
        s = "Case #%d: %s" % (case, result)
        output.write(s + "\n")
        logging.info(s)



if __name__ == "__main__":
    if len(sys.argv) < 2:
        print "expects filename"
        sys.exit(1)
    logging.basicConfig(level=logging.DEBUG)
    outfile = sys.argv[1] + ".out"
    main(open(sys.argv[1]), open(outfile, "w"))

