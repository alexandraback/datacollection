#!/usr/bin/python3

import getopt
import sys
import math
import itertools

if __name__ == "__main__":

    verbose = False
    fname = "input.txt"

    if sys.version_info[0] < 3:
        print("This script requires Python 3. (You are running %d.%d)" % (
            sys.version_info[0], sys.version_info[1])) 
        sys.exit()

    try:
        opts, args = getopt.getopt(sys.argv[1:], "hvf:",
                                   ["verbose","help","input="])
    except getopt.GetoptError as err:
        print (str(err)) 
        sys.exit(2)

    for o, a in opts:
        if o in ("-h", "--help"): sys.exit()
        elif o in ("-v", "--verbose"): verbose = True
        elif o in ("-f", "--input"): fname = a
        else: sys.exit()

    f = open(fname, "rt")
    ncases = int(f.readline())

    for c in range(ncases):
        K,L,S = [int(x) for x in f.readline().split()]

        iw = f.readline().strip()
        ow = f.readline().strip()

        ci = [xx for xx in itertools.product(iw,repeat = S)]
        l = len(ci)
        lc = 0
        maxb = 0

        for t in ci:
            compi = ''.join(t)
            r = [i for i in range(len(compi)) if compi.startswith(ow, i)]
            if  len(r) > maxb:
                maxb = len(r)
            lc += len(r)

        if verbose:
            print("max = %d, avg: %.2f %d out of %d" % (maxb, lc/l, lc, l))

        solution = maxb - lc/l

        if verbose:
            print("Case %d: %d %d %d" % (c+1, K,L,S))
            print(iw)
            print(ow)

        print("Case #%d: %f" % (c+1,solution))





        

        




