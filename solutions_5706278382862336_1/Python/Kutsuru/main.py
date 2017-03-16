#! /usr/bin/env python2
# -*- coding: utf-8 -*-

import sys
import math
from fractions import Fraction

def parse_input(filename):
    """
    Parse the input according to the following format
    """
    input_file = open(filename, "r")

    tc_number = int(input_file.readline())
    tc_list = []

    for i in range(tc_number):
        tc = {}
        tc['x'] = i + 1
        P, Q = input_file.readline().split('/')
        tc['P'] = int(P)
        tc['Q'] = int(Q)
        tc_list.append(tc)

    return tc_list

def main(argv):
    """
    """
    filename = argv[0]
    tc_list = parse_input(filename)
    for tc in tc_list:
        solve(tc)


def solve(tc):
    res = ""
    fraction = Fraction(tc.get('P'), tc.get('Q'))

    b = fraction.denominator.bit_length() - 1

    if (fraction.denominator - 2 ** b) != 0:
        res = "impossible"
    else:
        res = str(b - fraction.numerator.bit_length() + 1)

    print "Case #%i: %s" % (tc.get('x'), res)

if __name__ == "__main__":
    main(sys.argv[1:])
