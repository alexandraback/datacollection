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


class Sol:
    def __init__(self, A, nb_op):
        self.A = A
        self.nb_op = nb_op

    def __str__(self):
        return 'A=%d, nb_op=%d' % (self.A, self.nb_op)


def test_level(A, size, nb_this_size, nb_op):
    if size < A:
        #absorb
        return [Sol(A+size*nb_this_size, nb_op)]
    else:
        ret_l = []

        # Try to add:
        A_test = A
        nb_op_add = 0
        while A_test <= size:
            A_test += A_test -1
            nb_op_add += 1

        ret_l.append(Sol(A_test + size * nb_this_size, nb_op + nb_op_add))

        # Try to delete
        if nb_op_add > nb_this_size:
            # Might better to delete
            ret_l.append(Sol(A, nb_op + nb_this_size))
        return ret_l

def clean_sols(sols):
    # If several sols have the same nb_op, keep only the biggest size

    d = {}

    print 'in', [str(s) for s in sols]

    for sol in sols:
        if sol.nb_op in d:
            other_sol = d[sol.nb_op]
            if sol.A > other_sol:
                # Replace, this one is better
                d[sol.nb_op] = sol
        else:
            d[sol.nb_op] = sol


    ret = sorted(d.values(), key=lambda s:s.nb_op)
    ret2 = []
    # smallest nb op
    max_size = 0
    for s in ret:
        if s.A > max_size:
            max_size = s.A
            ret2.append(s)


    print 'ret', [str(s) for s in ret]
    print 'ret2', [str(s) for s in ret2]
    return ret2

def solve_case(case_no, A, sizes    ):
    print "-------------- New case", case_no

    s_nb = {} # Size -> nb
    A_init = A
    if A == 1:
        # Need to remove all
        return len(sizes)

    for s in sizes:
        s_nb[s] = 1 + s_nb.get(s, 0)

    sizes_sorted = sorted(s_nb.keys())

    poss = {} # level -> []

    for index, this_size in enumerate(sizes_sorted):
        poss[index] = []

        nb_this_size = s_nb[this_size]
        if index == 0:
            sols_to_try = [Sol(A_init, 0)]
        else:
            sols_to_try = poss[index-1]

        for sol in clean_sols(sols_to_try):
            poss[index] += test_level(sol.A, this_size, nb_this_size, sol.nb_op)


    last_sols = clean_sols(poss[index])
    nb_op = None
    for sol in last_sols:
        if nb_op is None or sol.nb_op < nb_op:
            nb_op = sol.nb_op

    return nb_op


def main(argv):

    f_out_name = argv[1].split(".")[0] + ".out"
    f_out = open(f_out_name, "w")

    fd = open(argv[1])
    nb_cases = int(fd.readline())


    for case_no in range(1, nb_cases+1):

        A, n = [int(item) for item in fd.readline().split()]
        sizes = [int(item) for item in fd.readline().split()]
        assert len(sizes) == n


        # Have read all stuff for this case:
        f_out.write( "Case #%d: %d\n" % (case_no,
                                         solve_case(case_no, A, sizes)
                                         )
                     )
        f_out.flush()

    f_out.close()

    for line in open(f_out_name):
        print line,



import sys
if __name__ == "__main__":
    main(sys.argv)
