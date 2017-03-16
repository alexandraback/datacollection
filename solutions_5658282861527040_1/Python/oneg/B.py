#!/usr/bin/env python
# coding: utf-8

#########################################################################
#########################################################################

"""
   File Name: gcj.py
      Author: Wan Ji
      E-mail: wanji@live.com
  Created on: Sat Apr 12 14:59:24 2014 CST
"""
DESCRIPTION = """
"""

import os
import sys
import argparse


def perr(msg):
    """ Print error message.
    """

    sys.stderr.write("%s" % msg)
    sys.stderr.flush()


def pinfo(msg):
    """ Print information message.
    """

    sys.stdout.write("%s" % msg)
    sys.stdout.flush()


def runcmd(cmd):
    """ Run command.
    """

    perr("%s\n" % cmd)
    os.system(cmd)


def getargs():
    """ Parse program arguments.
    """

    parser = argparse.ArgumentParser(description=DESCRIPTION,
                                     formatter_class=
                                     argparse.RawTextHelpFormatter)
    parser.add_argument('infile', type=str, help='input file')
    parser.add_argument('outfile', type=str, nargs='?', default=None,
                        help='output file')

    return parser.parse_args()


BITS = [0x01, 0x02, 0x04, 0x08, 0x10, 0x20, 0x40, 0x100, 0x200, 0x400]


def calc(A, B, K):
    """

    """
    if min(A, B) < K:
        return A * B

    cnt = K * A + K * B - K * K
    for a in range(K, A):
        for b in range(K, B):
            if a & b < K:
                cnt += 1
    return cnt


def main(args):
    """ Main entry.
    """

    if None == args.outfile:
        outfile = sys.stdout
    else:
        outfile = open(args.outfile, "w")

    with open(args.infile) as infile:
        T = int(infile.readline())
        for i in range(1, T + 1):
            [A, B, K] = [int(x) for x in infile.readline().split()]
            outfile.write("Case #%d: %d\n" % (i, calc(A, B, K)))

    if None != args.outfile:
        outfile.close()

if __name__ == '__main__':
    main(getargs())
