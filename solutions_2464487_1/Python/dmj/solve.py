#!/usr/bin/env python

import sys
import logging

def solve(r, t):
    c = 0
    while True:
        u = (2*r + 1)
        b
        if t < u:
            return c
        t -= u
        r += 2
        c += 1

def solve(r ,t):
    def f(N):
        return (2*r + 1) * N + 2 * N * (N-1)
    n = 1
    while f(n) < t:
        n *= 2
    hi = n
    low = 1
    while hi - low > 1:
        c = (hi + low) // 2
        if f(c) <= t:
            low = c
        else:
            hi = c
    logging.debug("t: %d, low: %d, f(low) %d %d", t, low, f(low), f(hi))
    if f(hi) == t:
        return hi
    else:
        return low



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

