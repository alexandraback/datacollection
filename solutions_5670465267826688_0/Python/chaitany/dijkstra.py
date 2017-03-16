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

global_arr = [[0,0,0,0,0],[0,1,2,3,4],[0,2,-1,4,-3],[0,3,-4,-1,2],[0,4,3,-2,-1]]

def calc_matrix(val1, val2):
    answer = global_arr[abs(val1)][abs(val2)]
    if val1*val2 < 0:
        return answer*(-1)
    else:
        return answer
    
def leading_product(d_string):
    product = [0 for n in d_string]
    for i in range(len(d_string)):
        if i == 0:
            product[i] = d_string[i]
        else:
            product[i] = calc_matrix(product[i-1], d_string[i])
    return product

def trailing_product(d_string):
    product = [0 for n in d_string]
    enum_range = range(len(d_string))
    enum_range.reverse()
    for i in enum_range:
        if i == len(d_string)-1:
            product[i] = d_string[i]
        else:
            product[i] = calc_matrix(d_string[i], product[i+1])
    return product

def latest_k_match(product, k):
    enum_range = range(len(product)) 
    enum_range.reverse()
    for i in enum_range:
        if i == len(product) - 1:
            continue
        if product[i] == k:
            return i
    return -1

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
        L = nums[0]
        X = nums[1]
        string_len = L*X
        i = i + 1
        d_string = ""
        for k in range(X):
            d_string = d_string + data[i][0:L]
        num_string = []
        for k in range(L*X):
            if d_string[k] == 'i':
                num_string.append(2)
            elif d_string[k] == 'j':
                num_string.append(3)
            else:
                num_string.append(4)
        lead_product = leading_product(num_string)
        trail_product = trailing_product(num_string)
        latest_k = latest_k_match(lead_product, 4)
        answer = "NO"
        #logger.info("num_string = {3} lead = {0} trail = {1} latest_k = {2}".format(lead_product, trail_product, latest_k, num_string))
        for k in range(L*X - 2):
            if lead_product[L*X - 1] == -1 and lead_product[k] == 2 and trail_product[k+1] == 2 and latest_k >= k + 1:
                answer = "YES"
                
        logger.info("Case #{0}: {1}".format(j+1, answer))

if __name__ == "__main__":
    main()
