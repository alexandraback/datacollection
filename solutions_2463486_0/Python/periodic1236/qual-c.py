#!/usr/bin/env python
#
# Copyright 2013 Super-Magician Inc. All Rights Reserved.

"""Google Code Jam 2013 Qualification - Problem C (Fair and Square)."""

__author__ = "mqian@caltech.edu (Mike Qian)"

from itertools import dropwhile, takewhile
import sys


FAIR_AND_SQUARE = [
    1,4,9,121,484,10201,12321,14641,40804,44944,1002001,1234321,4008004,
    100020001,102030201,104060401,121242121,123454321,125686521,400080004,
    404090404,10000200001,10221412201,12102420121,12345654321,40000800004,
    1000002000001,1002003002001,1004006004001,1020304030201,1022325232201,
    1024348434201,1210024200121,1212225222121,1214428244121,1232346432321,
    1234567654321,4000008000004,4004009004004
]


def main(args):
  with sys.stdin as f:
    num_cases = int(f.readline())
    for case in xrange(num_cases):
      a, b = map(int, f.readline().split())
      number = len(list(takewhile(lambda x: x <= b,
                                  dropwhile(lambda x: x < a, FAIR_AND_SQUARE))))
      print "Case #%d: %d" % (case+1, number)


if __name__ == "__main__":
  main(sys.argv[1:])