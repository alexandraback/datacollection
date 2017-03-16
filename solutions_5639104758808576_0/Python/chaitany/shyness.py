#!/usr/bin/env python
#
# Copyright (c) 2013 NetApp, Inc.
# All rights reserved.
#
"""
"""
# IMPORTANT
# Run as 
# python template.py < A-small-practice.in >& A-small-practice.out

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

# This function will take a certain number, and generate the 'base' representation
# of it. And it will output that in the form of a array ..
# you have to provide how many 'bits' you want .. if there are excess, the leading
# ones will be zero.
def convert_number_to_bit_string(number, num_bits, base=2):
    string_bits = [0 for i in range(num_bits)]
    index = len(string_bits) - 1
    while index >= 0:
        string_bits[index] = number%base
        number = number / base
        index = index -1
    return string_bits


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
        nums = data[i].split()
        Smax = int(nums[0])
        S_values = [int(n) for n in nums[1]]
        net_sum_so_far = 0
        answer = 0
        for k in range(Smax+1):
            if k == 0:
                net_sum_so_far = net_sum_so_far + S_values[k]
                continue
            if net_sum_so_far >= k:
                net_sum_so_far = net_sum_so_far + S_values[k]
                continue
            if net_sum_so_far < k:
                answer = answer + k - net_sum_so_far
                net_sum_so_far = S_values[k] + k 
                continue
        logger.info("Case #{0}: {1}".format(j+1, answer))

if __name__ == "__main__":
    main()
