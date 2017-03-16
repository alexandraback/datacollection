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
        A, B, K = [int(x) for x in input_file.readline().split(' ')]
        tc['A'] = A
        tc['B'] = B
        tc['K'] = K
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
    res = 0

    A = tc.get('A')
    B = tc.get('B')
    K = tc.get('K')

    if A < K or B < K:
        res = A * B
    else:
        for i in range(K, A):
            for j in range(K, B):
                if i&j < K:
                    res += 1

        res += (A + B) * K - K**2

    print "Case #%i: %i" % (tc.get('x'), res)

if __name__ == "__main__":
    main(sys.argv[1:])
