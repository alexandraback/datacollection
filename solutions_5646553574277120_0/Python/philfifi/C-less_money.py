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

def test_all_possible(C, D, V, values):
    all_possible_v = set()

    for i in range(2**len(values) ):

        t_value = 0
        iterat = 0
        while i > 0:
            i, r = divmod(i, 2)
            if r:
                t_value += values[iterat]
            iterat += 1
        if t_value <= V:
            all_possible_v.add(t_value)
    return (V - len(all_possible_v) +1) == 0

def can_do(value, my_values, C):

    for i in range(2**len(my_values) ):

        t_value = 0
        iterat = 0
        while i > 0:
            i, r = divmod(i, 2)
            if r:
                t_value += my_values[iterat]
            iterat += 1

        if t_value == value:
            return True

    return False



def solve_case(case_no, C, D, V, values    ):
    print "-------------- New case", case_no
    print C, D, V, values

    my_values = sorted(values)

    for i in range(V+1):
        if can_do(i, my_values, C):
            continue
        else:
            my_values.append(i)
            my_values.sort()

    print "my_values", my_values

    return len(my_values) - len(values)


def main(argv):

    f_out_name = argv[1].split(".")[0] + ".out"
    f_out = open(f_out_name, "w")

    fd = open(argv[1])
    nb_cases = int(fd.readline())


    for case_no in range(1, nb_cases+1):

        C, D, V = [int(item) for item in fd.readline().split()]
        values = [int(item) for item in fd.readline().split()]


        # Have read all stuff for this case:
        s = solve_case(case_no, C, D, V, values)
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
