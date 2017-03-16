#! /usr/bin/env python2
# -*- coding: utf-8 -*-

import sys
from math import factorial as fact

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
        N, M, K = [int(x) for x in input_file.readline().split(' ')]
        tc['N'] = N
        tc['M'] = M
        tc['K'] = K
        tc_list.append(tc)

    return tc_list

def main(argv):
    filename = argv[0]
    tc_list = parse_input(filename)
    for tc in tc_list:
        solve(tc)


def solve(tc):
    res = 0
    N = tc.get('N')
    M = tc.get('M')
    K = tc.get('K')

    if K < 5:
        res = K
    elif N < 3 or M < 3:
        res = K
    elif N == 3 and M == 3:
        res = K - 1
    elif (N == 3 and M == 4) or (N == 4 or M == 3):
        if (K < 8):
            res = K - 1
        else:
            res = K - 2
    elif (N == 3 and M == 5) or (N == 5 or M == 3):
        if (K < 8):
            res = K - 1
        if (K < 11):
            res = K - 2
        else:
            res = K - 3
    elif (N == 3 and M == 6) or (N == 6 or M == 3):
        if (K < 8):
            res = K - 1
        if (K < 11):
            res = K - 2
        if (K < 14):
            res = K - 3
        else:
            res = K - 4
    elif N == 4 and M == 4:
        if (K < 8):
            res = K - 1
        if (K < 10):
            res = K - 2
        if (K < 12):
            res = K - 3
        else:
            res = K - 4
    elif (N == 4 and M == 5) or (N == 5 or M == 4):
        if (K < 8):
            res = K - 1
        if (K < 10):
            res = K - 2
        if (K < 12):
            res = K - 3
        if (K < 14):
            res = K - 4
        if (K < 16):
            res = K - 5
        else:
            res = K - 6


    print "Case #%i: %i" % (tc.get('x'), res)

if __name__ == "__main__":
    main(sys.argv[1:])
