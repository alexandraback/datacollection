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



def solve_case(case_no, pv_l    ):
    print "-------------- New case", case_no

    print pv_l

    X = sum(pv_l)
    lowest = min(pv_l)
    highest = max(pv_l)

    pv_idx_l = []
    # first is the highest
    for i in range(len(pv_l)):
        pv_idx_l.append( (i, pv_l[i]) )

    pv_idx_l.sort(key=lambda x:x[1], reverse=True)

    print pv_idx_l

    ret_l = [0.] * len(pv_idx_l)


    last_ratio = 0.
    last_ji = None
    nb_eliminable = len(pv_l)

    for idx, ji in pv_idx_l:

        print "-"*10
        print 'ji', ji
        print 'last_ji', last_ji
        print 'last_ratio', last_ratio

        # How many are under ?
        under = 0
        for ji2 in pv_l:
            diff = ji - ji2
            if diff > 0:
                under += diff

        if under >= X:
            # Cannot be eliminated
            ret_l[idx] = 0.
            last_ratio = 0.
            nb_eliminable -= 1
        else:
            if last_ratio == 0.:
                print "last = 0"
                left_points = X - under
                last_ratio = left_points * 100. / X / nb_eliminable
                ret_l[idx] = last_ratio
            else:
                last_ratio = last_ratio + (last_ji - ji)*100. / X
                ret_l[idx] = last_ratio

        last_ji = ji

        print ret_l[idx]



    return " ".join( ["%.6f" % i for i in ret_l ] )


def main(argv):

    f_out_name = argv[1].split(".")[0] + ".out"
    f_out = open(f_out_name, "w")

    fd = open(argv[1])
    nb_cases = int(fd.readline())


    for case_no in range(1, nb_cases+1):

        things = [int(item) for item in fd.readline().split()]

        nb = things[0]
        point_value = things[1:]


        # Have read all stuff for this case:
        f_out.write( "Case #%d: %s\n" % (case_no,
                                         solve_case(case_no, point_value)
                                         )
                     )
        f_out.flush()

    f_out.close()

    for line in open(f_out_name):
        print line,



import sys
if __name__ == "__main__":
    main(sys.argv)
