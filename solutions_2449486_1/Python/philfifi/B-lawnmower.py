#!/usr/bin/python2

"""
  Google Code Jam 2013
  Philfifi  --  http://www.pluc.fr
  All rigths reserved
"""

from math import sqrt
from decimal import *
getcontext().prec = 100

#import psyco
#psyco.full()

_debug = 0



def solve_case(case_no, N, M, a):
    print "-------------- New case", case_no
    yes = "YES"
    no = "NO"

    max_line = [None] * N
    for i in range(N):
        max_line[i] = max(a[i])

    max_col = [None] * M
    for j in range(M):
        max_col[j] = max( [ a[x][j] for x in range(N)] )

    for i in range(N):
        for j in range(M):
            test = a[i][j]
#            print i, j, test
#            print "max_line", max_line[i]
#            print "max_col ", max_col[j]
            if test < max_line[i] and test < max_col[j]:
                return no

    return yes


def main(argv):

    f_out_name = argv[1].split(".")[0] + ".out"
    f_out = open(f_out_name, "w")

    fd = open(argv[1])
    nb_cases = int(fd.readline())


    for case_no in range(1, nb_cases+1):

        N, M = [ int(item) for item in fd.readline().split() ]

        a = []
        for _ in range(N):
            a.append( [int(item) for item in fd.readline().split()] )
            assert len(a[-1]) == M

        assert len(a) == N

        # Have read all stuff for this case:
        f_out.write( "Case #%d: %s\n" % (case_no,
                                         solve_case(case_no, N, M, a)
                                         )
                     )
        f_out.flush()

    f_out.close()

    for line in open(f_out_name):
        print line,



import sys
if __name__ == "__main__":
    main(sys.argv)
