#!/usr/bin/python2

"""
  Google Code Jam 2012
  Philfifi  --  http://www.pluc.fr
  All rigths reserved
"""

from math import sqrt
from decimal import *
getcontext().prec = 100

#import psyco
#psyco.full()

_debug = 0


def get_subset(l, num):
    ret_l = []
    for i in range(len(l)):
        if num & 1 << i:
            ret_l.append(l[i])

    return ret_l

def get_sum(l, num):
    ret = 0
    for i in range(len(l)):
        if num & 1 << i:
            ret += l[i]

    return ret


def solve_case(case_no, N, l    ):
    print "-------------- New case", case_no

    sum_d = {}

    found = False

    for i in range(2**N):
        the_sum = get_sum(l, i)
        if the_sum in sum_d:
            s1_l = get_subset(l, sum_d[the_sum])
            s2_l = get_subset(l, i)
            found = True
            break
        else:
            sum_d[the_sum] = i

    if found:
        ret_s = " ".join([str(i) for i in s1_l])
        ret_s += "\n"
        ret_s += " ".join([str(i) for i in s2_l])

    return ret_s


def main(argv):

    f_out_name = argv[1].split(".")[0] + ".out"
    f_out = open(f_out_name, "w")

    fd = open(argv[1])
    nb_cases = int(fd.readline())


    for case_no in range(1, nb_cases+1):

        things = [int(item) for item in fd.readline().split()]


        # Have read all stuff for this case:
        f_out.write( "Case #%d:\n%s\n" % (case_no,
                                         solve_case(case_no, things[0], tuple(sorted(things[1:])))
                                         )
                     )
        f_out.flush()

    f_out.close()

    for line in open(f_out_name):
        print line,



import sys
if __name__ == "__main__":
    main(sys.argv)
