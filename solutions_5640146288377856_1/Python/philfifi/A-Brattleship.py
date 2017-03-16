#!/usr/bin/python2

"""
  Google Code Jam 2015
  Philfifi  --  http://www.pluc.fr
  All rigths reserved
"""

from math import sqrt
from decimal import *
getcontext().prec = 100

#import psyco
#psyco.full()

_debug = 0



def solve_case(case_no, R, C, W    ):
    print "-------------- New case", case_no, R, C, W


    if W == 1:
        return R*C

    n = R* (C/W)

    if C % W == 0:
        n+=W-1
    else:
        n+=W


    return n


def main(argv):

    f_out_name = argv[1].split(".")[0] + ".out"
    f_out = open(f_out_name, "w")

    fd = open(argv[1])
    nb_cases = int(fd.readline())


    for case_no in range(1, nb_cases+1):

        R, C, W = [int(item) for item in fd.readline().split()]


        # Have read all stuff for this case:
        s = solve_case(case_no, R, C, W)
        print s
        f_out.write( "Case #%d: %d\n" % (case_no,
                                         s
                                         )
                     )
        f_out.flush()

    f_out.close()

    for line in open(f_out_name):
        print line,



import sys
if __name__ == "__main__":
    main(sys.argv)
