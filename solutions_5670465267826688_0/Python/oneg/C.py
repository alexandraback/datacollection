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


ORI_MAP = [
    ['1',  'i',  'j',  'k'],
    ['i', '-1',  'k', '-j'],
    ['j', '-k', '-1',  'i'],
    ['k',  'j', '-i', '-1'],
]

CHAR_MAP = {
    '1':  0, 'i':  1, 'j':  2, 'k':  3,
    '-1': 4, '-i': 5, '-j': 6, '-k': 7,
}

CHAR_ARR = [
    '1', 'i', 'j', 'k', '-1', '-i', '-j', '-k',
]

DIG_MAP = [
    [0, 1, 2, 3, 4, 5, 6, 7],
    [1, 4, 3, 6, 5, 0, 7, 2],
    [2, 7, 4, 1, 6, 3, 0, 5],
    [3, 2, 5, 4, 7, 6, 1, 0],
    [4, 5, 6, 7, 0, 1, 2, 3],
    [5, 0, 7, 2, 1, 4, 3, 6],
    [6, 3, 0, 5, 2, 7, 4, 1],
    [7, 6, 1, 0, 3, 2, 5, 4],
]

# DIG_MAP = None


def get_i_pos(digits, L, ntotal):
    i_pos = []
    cur = 0
    for i in xrange(ntotal):
        cur = DIG_MAP[cur][digits[i % L]]
        if cur == 1:
            i_pos.append(i)
    return i_pos


def get_k_pos(digits, L, ntotal):
    k_pos = []
    cur = 0
    for k in xrange(ntotal-1, 0, -1):
        cur = DIG_MAP[digits[k % L]][cur]
        if cur == 3:
            k_pos.append(k)
    return k_pos


def calc_slice(digits, start, end):
    return 0


def solve(L, X, chars):
    ntotal = L * X
    if ntotal < 3:
        return "NO"
    elif ntotal == 3:
        return "YES" if chars == "ijk" else "NO"

    digits = [CHAR_MAP[c] for c in chars]
    i_pos = get_i_pos(digits, L, ntotal)
    k_pos = get_k_pos(digits, L, ntotal)

    for i in i_pos:
        j = i + 1
        cur = 0
        for k in k_pos:
            while j < k:
                cur = DIG_MAP[cur][digits[j % L]]
                j += 1
            if cur == 2:
                return "YES"

    return "NO"


def main(args):
    """ Main entry.
    """
    # global DIG_MAP
    # DIG_MAP = [[-1 for j in range(8)] for i in range(8)]
    # for i in range(8):
    #     for j in range(8):
    #         ri = i / 4
    #         rj = j / 4
    #         vi = i % 4
    #         vj = j % 4
    #         val = CHAR_MAP[ORI_MAP[vi][vj]]
    #         if (ri and not rj) or (rj and not ri):
    #             val = (val + 4) if val < 4 else (val - 4)
    #         DIG_MAP[i][j] = val

    if None == args.outfile:
        outfile = sys.stdout
    else:
        outfile = open(args.outfile, "w")

    with open(args.infile) as infile:
        T = int(infile.readline())
        for i in range(1, T + 1):
            [L, X] = [int(x) for x in infile.readline().split()]
            chars = infile.readline().strip()
            outfile.write("Case #%d: %s\n" % (i, solve(L, X, chars)))

    if None != args.outfile:
        outfile.close()

if __name__ == '__main__':
    main(getargs())
