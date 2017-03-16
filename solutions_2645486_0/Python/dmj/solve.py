#!/usr/bin/env python

import sys
import logging

def solve(E, R, Vs):
    cache = {}
    def go(e, vs):
        if len(vs) == 0:
            return 0
        key = (e, len(vs))
        if key in cache:
            return cache[key]
        best = 0 
        for i in range(e+1):
            ep = min(E, e-i+R)
            s = i * vs[0]
            s += go(ep, vs[1:])
            best = max(best, s)
        cache[key] = best
        return best
    return go(E, Vs)


def main(lines, output):
    T = int(lines.next())
    for case in xrange(1,T+1):
        E, R, N = [int(x) for x in lines.next().split()]
        Vs = [int(x) for x in lines.next().split()]
        r = solve(E, R, Vs)
        s = "Case #%d: %s" % (case, r)
        output.write(s + "\n")
        logging.info(s)



if __name__ == "__main__":
    if len(sys.argv) < 2:
        print "expects filename"
        sys.exit(1)
    logging.basicConfig(level=logging.DEBUG, filename="logfile.txt", filemode="w")
    outfile = sys.argv[1] + ".out"
    main(open(sys.argv[1]), open(outfile, "w"))

