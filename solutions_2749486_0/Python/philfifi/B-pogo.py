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

class Part:
    def __init__(self, X, Y, n, log):
        self.X = X
        self.Y = Y
        self.n = n
        self.log = log
    def up(self):
        return Part(self.X,
                    self.Y+self.n,
                    self.n+1,
                    self.log+'N')
    def down(self):
        return Part(self.X,
                    self.Y-self.n,
                    self.n+1,
                    self.log+'S')
    def left(self):
        return Part(self.X-self.n,
                    self.Y,
                    self.n+1,
                    self.log+'W')
    def right(self):
        return Part(self.X+self.n,
                    self.Y,
                    self.n+1,
                    self.log+'E')

    def __str__(self):
        ret_l = []
        ret_l.append("X=%3d" % self.X)
        ret_l.append("Y=%3d" % self.Y)
        ret_l.append("n=%3d" % self.n)
        ret_l.append(self.log)
        return '\n'.join(ret_l)

def solve_case(case_no, dest_X, dest_Y    ):
    print "-------------- New case", case_no

    sols = [Part(0,0, 1, "")]


    while True:
        # do all the moves
        n = []
        print "-------------------------------------------------------------------------"
        print sols[0].n
        for s in sols:
            n += [s.up(), s.down(), s.left(), s.right()]

        # Filter
        d = {}
        for s in n:
            if (s.X, s.Y, s.n) not in d:
                d[(s.X, s.Y, s.n)] = s

        n = d.values()

        # test them
        for s in n:
            if s.X == dest_X and s.Y == dest_Y:
                print s
                return s.log

        sols = n


def main(argv):

    f_out_name = argv[1].split(".")[0] + ".out"
    f_out = open(f_out_name, "w")

    fd = open(argv[1])
    nb_cases = int(fd.readline())


    for case_no in range(1, nb_cases+1):

        X,Y = [int(item) for item in fd.readline().split()]


        # Have read all stuff for this case:
        f_out.write( "Case #%d: %s\n" % (case_no,
                                         solve_case(case_no, X, Y)
                                         )
                     )
        f_out.flush()

    f_out.close()

    for line in open(f_out_name):
        print line,



import sys
if __name__ == "__main__":
    main(sys.argv)
