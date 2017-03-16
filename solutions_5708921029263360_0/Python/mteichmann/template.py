#!/usr/bin/env python
# -*- coding: utf-8 -*-

import numpy as np
import itertools as it
import pickle
import logging
import ipdb
import sys

reload(logging)
logging.basicConfig(format='%(asctime)s %(levelname)s %(message)s',
                    level=logging.DEBUG,
                    stream=sys.stdout)


def special_1(num):
    sol = ""


    return sol



def solve(line):
    num = line.split(" ")
    num = np.array(map(int, num))
    assert(len(num) == 4)

    count = 0

    sol = ""
    this_count = None
    while num[3] > 1:
        this_count = 0
        for i in range(3):
            num[i] = min(num[i], num[3])
        for i in it.product(range(1,num[0]+1),range(1,num[1]+1),range(1,num[2]+1)):
            line = "\n"
            for j in i:
                line = line + str(j) + " "
            line = line 
            sol = sol + line
            count = count + 1
            this_count = this_count + 1
        num[3] = num[3] - num[2]
        if this_count < 2:
            # assert(this_count == count)
            break

    if this_count is None or this_count > 1:
        if num[3] == 1:
            for i in range(1, num[1]+1):
                sol = sol + "\n1 %i %i" % (i,i)
                count = count + 1

    return str(count)  + sol


if __name__ == "__main__":
    testcases = input()

    for caseNr in xrange(1, testcases+1):
        line = raw_input()
        print("Case #%i: %s" % (caseNr, solve(line)))
