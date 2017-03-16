#!/usr/bin/python2

"""
  Google Code Jam 2014
  Philfifi  --  http://www.pluc.fr
  All rigths reserved
"""

from math import sqrt, log
from decimal import *
getcontext().prec = 100

#import psyco
#psyco.full()

_debug = 0

from fractions import Fraction


def solve_case(case_no, P, Q    ):
    print "-------------- New case", case_no

    r = Fraction(P, Q)

    print r

    first = True
    while 1:
        if r.denominator % 2 == 1:
            return "impossible"

        pow2_P = int(log(r.numerator)/log(2))
        pow2_Q = int(log(r.denominator)/log(2))

        p = pow2_Q - pow2_P
        if p == 0:
            return "impossible"

        print "p", p
        r = r - Fraction(1, 2**p)

        if r <0:
            return "impossible"

        print "new r", r

        if first:
            ret = p
            first = False

        if r.numerator == 0:
            break

    return ret


def main(argv):

    f_out_name = argv[1].split(".")[0] + ".out"
    f_out = open(f_out_name, "w")

    fd = open(argv[1])
    nb_cases = int(fd.readline())


    for case_no in range(1, nb_cases+1):

        P, Q = [int(item) for item in fd.readline().split("/")]


        # Have read all stuff for this case:
        f_out.write( "Case #%d: %s\n" % (case_no,
                                         solve_case(case_no, P, Q)
                                         )
                     )
        f_out.flush()

    f_out.close()

    for line in open(f_out_name):
        print line,



import sys
if __name__ == "__main__":
    main(sys.argv)
