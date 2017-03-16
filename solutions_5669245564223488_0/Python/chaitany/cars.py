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
        i = i+1
        nums = [int(n) for n in data[i].split()]
        N = nums[0]
        i = i+1
        Set_of_strings = data[i].split()
        Set_of_strings = sorted(Set_of_strings)
        #logger.info("N is {0} set = {1}".format(N, Set_of_strings))
        num_cases = 0
        feas = check_feasiblity(Set_of_strings)
        if feas == -1:
            logger.info("Case #{0}: 0".format(j+1))
            continue
        index_lists = break_into_indy_strings(Set_of_strings)
        #logger.info("Set = {0} index_lists = {1}".format(Set_of_strings, index_lists))
        num_perms = 1
        start_index = 0
        for index in index_lists:
            num_perms = ((num_perms%1000000007) * calculate_num_perms(Set_of_strings, start_index, index -1))%1000000007
            start_index = index
        num_perms = ((num_perms%1000000007) * calculate_num_perms(Set_of_strings, start_index, len(Set_of_strings)-1))%1000000007
        num_perms = ((num_perms%1000000007) * factorial(len(index_lists)+1))% 1000000007
        logger.info("Case #{0}: {1}".format(j+1, num_perms))

def check_feasiblity(Set):
    char = 'a'
    while char <= 'z':
        found = 0
        break_s = 0
        for string in Set:
            list_s = list(string)
            for string_1 in list_s:
                if string_1 == char and found == 0:
                    found = 1
                elif found == 1 and string_1 != char:
                    break_s = 1
                elif break_s == 1 and string_1 == char:
                    #logger.info("Found pattern broker for {0} at char {1}".format(Set, char))
                    return -1
        #logger.info("Char is {0}".format(char))
        char = chr(ord(char)+1)
    return 1

def break_into_indy_strings(Set):
    prev_char = '0'
    index_lists = []
    index = 0
    for string in Set:
        list_s = list(string)
        if prev_char != '0' and list_s[0] != prev_char:
            index_lists.append(index)
        prev_char = list_s[len(list_s)-1]
        index = index +1
       
    return index_lists 

def calculate_num_perms(Set, start_index, end_index):
    num_perms = 1
    prev_string = ''
    num_dups = 0
    for i in range(end_index+1):
        if i < start_index:
            continue
        if prev_string == '':
            prev_string = Set[i]
            num_dups = num_dups + 1
            continue
        if Set[i] == prev_string:
            num_dups = num_dups + 1
            #logger.info("In if part for Set = {0} prev_string {1} num_dups = {2}".format(Set[i], prev_string, num_dups))
        else:
            #logger.info("in else part for Set = {0} prev_string {1}".format(Set[i], prev_string))
            num_perms = ((num_perms % 1000000007) * factorial(num_dups))% 1000000007
            num_dups = 1
            prev_string = Set[i]
    #logger.info("Return value of calc of Set {0} sind = {1} eind = {2} answer = {3}".format(Set, start_index, end_index, num_perms))
    return ((num_perms%1000000007) * factorial(num_dups))% 1000000007
             
        
def factorial(num):
    answer = 1
    while num >1:
        answer = ((answer % 1000000007) * (num % 1000000007)) % 1000000007
        num = num - 1
    return answer
    
if __name__ == "__main__":
    main()
