#!/usr/bin/env python
#
# Copyright (c) 2013 NetApp, Inc.
# All rights reserved.
#
"""
"""

from __future__ import print_function
import argparse
import getpass
import glob
import imp
import itertools
import logging
import pkg_resources
import pkgutil
import sys
import re
import ystockquote
import requests
import threading
from multiprocessing import Process
import time

logger = logging.getLogger(__name__)

def main():
    streamformat = "%(message)s"
    logging.basicConfig(level=logging.INFO,
                        format=streamformat)
    data = sys.stdin.readlines()
    i = 0
    nums = [int(n) for n in data[i].split()]
    num_test_cases = nums[0]
    for j in range(num_test_cases):
        i = i + 1
        nums = data[i].split('/')[0]
        P = long(nums)
        nums = data[i].split('/')[1]
        Q = long(nums)
        #logger.info("P is {0} Q is {1}".format(P,Q))
        impossible = 0
        P_2s = highest_divisible(P)
        Q_2s = highest_divisible(Q)
        #logger.info("P is {0} Q is {1}".format(P_2s,Q_2s))
        P_1 = P/pow(2,P_2s)
        Q_1 = Q/pow(2,P_2s)
        num_ancestors = -1
        if Q_1 % pow(2, Q_2s-P_2s) != 0:
            impossible = 1
        else:
            quotient = Q_1/pow(2, Q_2s-P_2s)
            if P_1 % quotient != 0:
                impossible = 1
            else:
                num_ancestors = Q_2s-P_2s
                lower_n = lowest_before(P_1/quotient)
                num_ancestors = num_ancestors - lower_n
        if impossible == 1 or num_ancestors > 40:
            logger.info("Case #{0}: impossible".format(j+1))
        else:
            logger.info("Case #{0}: {1}".format(j+1, num_ancestors)) 
        if num_ancestors == 40:
            logger.info("WARNING")
         

def highest_divisible(val):
    remaining = val
    no_of_2s = 0
    while remaining%2 == 0:
        no_of_2s = no_of_2s +1
        remaining = long(remaining/2)
    return no_of_2s

def lowest_before(val):
    remaining = val
    no_of_2s = 0
    while val - pow(2, no_of_2s) >= 0:
        remaining = no_of_2s
        no_of_2s = no_of_2s + 1
    return no_of_2s - 1

if __name__ == "__main__":
    main()
