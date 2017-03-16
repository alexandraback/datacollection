#!/usr/bin/env python

import numpy as np
import sys
import re
import os
from fractions import Fraction
import itertools

def remove_doublons(s):
    if len(s) == 1:
        return s
    else:
        out = [s[0]]
        for i in range(1, len(s)):
            if s[i] != s[i-1]:
                out.append(s[i])
    return ''.join(out)

def reduce_doublons(l):
    out = []
    while l:
        s = l.pop()
        ss = remove_doublons(s)
        out.append(ss)
    return out

def is_valid(s):
    out = True
    l = list(s)
    seen = []
    c_prev = '0'
    while out and l:
        c = l.pop()
        if c != c_prev:
            if c in seen:
                out = False
            else:
                seen.append(c)
                c_prev = c
    return out


def solve(N, l):
    out = 0
    l = reduce_doublons(l)
    for ll in itertools.permutations(l):
        if is_valid(''.join(ll)):
            out += 1
    return out

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
        N = int(f.readline())
        l = f.readline().split()
        #print N
        #print l

        # call the function that solves the problem
        sys.stderr.write("solving case %d\n" % (i+1))
        answer = solve(N, l)

        # print the answer
        print "Case #%d: %s" % (i+1, answer)

    # close output_stream
    if output_file is not None:
        sys.stdout = sys.__stdout__
        output_stream.close()


if __name__ == '__main__': main()
