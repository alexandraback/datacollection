#!/usr/bin/env python

import numpy as np
import sys
import re
import os
from fractions import Fraction


def is_exp_two(n):
    if n == 1:
        return True
    else:
        r = n % 2
        m = n/2
        return (r == 0) and is_exp_two(m)

def solve(P, Q):
    a = Fraction(P, Q)
    P = a.numerator
    Q = a.denominator
    if not is_exp_two(Q):
        return "impossible"
    elif P >= Q/2:
        return 1
    else:
        return 1 + solve(P, Q/2)


def main():
    # check input arguments
    if len(sys.argv) > 1:
        input_file = sys.argv[1]
    else:
        sys.stderr.write("Usage:\n")
        sys.stderr.write("\t%s input_file\n" % sys.argv[0])
        sys.exit(1)

    # check if input file name fits the model '{A,B,C}-{small,large}-{int}.in'
    output_file = None
    if re.search('[A,B,C]-(small|large)-(\d+).in', input_file) is not None:
        output_file = '%s.out' % input_file.split('.')[0]
        output_stream = open(output_file, 'w')
        sys.stdout = output_stream

    # open input file
    f = open(input_file)
    T = int(f.readline())
    sys.stderr.write("%d test cases\n" % T)

    for i in range(T):
        # read input data
        l = f.readline().split('/')
        P = int(l[0])
        Q = int(l[1])
        #print P, Q

        # call the function that solves the problem
        answer = solve(P, Q)

        # print the answer
        print "Case #%d: %s" % (i+1, answer)

    # close output_stream
    if output_file is not None:
        sys.stdout = sys.__stdout__
        output_stream.close()


if __name__ == '__main__': main()
