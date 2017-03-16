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
import bisect


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

#USE THE function bisect.insort() whenever necessary
#If a is sorted in ascending order, e.g a = [5, 7, 10, 17]
# bisect.insort(a, 12) will insert 12 into the sorted array using binary search.
# bisect.insort(a, 12) will result in [5, 7, 10, 12, 17]

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
        i = i+1
        nums = [int(n) for n in data[i].split()]
        D = nums[0]
        i = i+1
        P_values = [int(n) for n in data[i].split()]
        P_values = sorted(P_values)
        optimal_minutes_so_far = -1
        highest_value = P_values[-1]
        for k in range(1, highest_value+1):
            special_minutes = 0
            for k2 in range(D):
                if (P_values[k2] > k):
                    if P_values[k2]%k == 0:
                        special_minutes = special_minutes + (P_values[k2]/k) - 1
                    else:
                        special_minutes = special_minutes + (P_values[k2]/k)
            if highest_value >= k:
                value = special_minutes + k
                if optimal_minutes_so_far == -1:
                    optimal_minutes_so_far = value
                elif value < optimal_minutes_so_far:
                    optimal_minutes_so_far = value
            else:
                value = special_minutes + highest_value
                if optimal_minutes_so_far == -1:
                    optimal_minutes_so_far = value
                elif value < optimal_minutes_so_far:
                    optimal_minutes_so_far = value
                 
        logger.info("Case #{0}: {1}".format(j+1, optimal_minutes_so_far))

if __name__ == "__main__":
    main()
