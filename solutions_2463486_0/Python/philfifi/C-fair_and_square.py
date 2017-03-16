#!/usr/bin/python2

"""
  Google Code Jam 2013
  Philfifi  --  http://www.pluc.fr
  All rigths reserved
"""
import itertools

from math import sqrt
from decimal import *
getcontext().prec = 100

#import psyco
#psyco.full()

_debug = 0



def is_fair(i):
    i_str = str(i)
    l = len(i_str)

    for pos in range(l/2):
        if i_str[pos] != i_str[-(pos+1)]:
            return False

    return True

def get_fair_and_square1(max):
    fair_and_square = []
    for i in range(max):
        if is_fair(i) and is_fair(i*i):
            print i
            fair_and_square.append(i)
    return fair_and_square

def get_comb_l(nb_figures):
    MAX_FIGURE = 2

    if nb_figures == 1:
        return [range(10)]

    adder_l = []
    for n in range(nb_figures/2):
        adder = (10 ** n) + (10 ** (nb_figures - n-1))
#        print "%10d" % adder
        adder_l.append(adder)

    # list of adders is ready
    nb_adders = len(adder_l)

    comb_l = [None] * nb_adders

    comb_l[0] = [adder_l[0] * n for n in range(1,2+1)]
    for i in range(1, nb_adders):
        comb_l[i] = [adder_l[i] * n for n in (0, 1)]


    if nb_figures % 2:
        adder_middle = 10**(nb_figures/2)
        comb_l.append( [adder_middle * n for n in range(2+1)] )
#        print "%10d" % adder_l[-1]


    return comb_l

def get_palindromes(nb_figures, low, high):
    nb = 0
    comb_l = get_comb_l(nb_figures)
    for pal_l in itertools.product(*comb_l):
        pal = sum(pal_l)
        sqr = pal**2
        if is_fair(sqr):
            if low <= sqr:
                if sqr <= high:
                    nb += 1
                else:
                    break
    return nb

def solve_case(case_no, A, B    ):
    print "-------------- New case", case_no
    print A, B

    nb_figures_sA = len(str(int(sqrt(A))))
    nb_figures_sB = len(str(1+int(sqrt(B))))

    print nb_figures_sA, nb_figures_sB

    nb = 0
    for nb_figure in range(nb_figures_sA, nb_figures_sB+1):
        nb += get_palindromes(nb_figure, A, B)

    return nb



#    for adder in (
#    for pos in range(nb_figures/2):
#        i =

#    range

def main(argv):

    f_out_name = argv[1].split(".")[0] + ".out"
    f_out = open(f_out_name, "w")

    fd = open(argv[1])
    nb_cases = int(fd.readline())


#    get_fair_and_square1(10**7)
#    get_palindromes(11)#37
#    get_palindromes(12)#27
#    get_palindromes(13)#60
#    get_palindromes(14)#43

    for case_no in range(1, nb_cases+1):

        A, B = [int(item) for item in fd.readline().split()]


        # Have read all stuff for this case:
        f_out.write( "Case #%d: %d\n" % (case_no,
                                         solve_case(case_no, A, B)
                                         )
                     )
        f_out.flush()

    f_out.close()

    for line in open(f_out_name):
        print line,



import sys
if __name__ == "__main__":
    main(sys.argv)
