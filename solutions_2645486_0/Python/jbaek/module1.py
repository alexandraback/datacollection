#-------------------------------------------------------------------------------
# Name:        module1
# Purpose:
#
# Author:      Jackie
#
# Created:     26/04/2013
# Copyright:   (c) Jackie 2013
# Licence:     <your licence>
#-------------------------------------------------------------------------------

import itertools
from decimal import *

from math import *

ends = []

def main():
    f = open("C:\Users\Jackie\Documents\Project Euler\Python\prob81.txt")
    lines = f.readlines()
    cases = int(lines.pop(0))
    for i in range(cases):
        ends = []
        print "Case #%d:" %(i+1),
        first = lines.pop(0).split()
        second = lines.pop(0).split()
        E = int(first[0])
        R = int(first[1])
        N = int(first[2])
        values = [int(v) for v in second]
        recurse(E, E, R, values, 0, N, 0, ends)
        print max(ends)

def recurse(curr_energy, maximum, regain, values, curr_index, length, gainedSoFar, ends):
    if curr_index == length:
        ends.append(gainedSoFar)
        return
    curr_value = values[curr_index]
    for i in range(curr_energy+1):
        gain = i*curr_value
        recurse(min(curr_energy-i+regain, maximum), maximum, regain, values, curr_index+1, length, gainedSoFar+gain, ends)
    """
    # spend all
    gain = curr_energy*curr_value
    recurse(regain, maximum, regain, values, curr_index+1, length, gainedSoFar+gain, ends)

    # determine if spend none or spend some

    # enough to regain
    if (maximum-curr_energy<regain):
        energy_spent = curr_energy+regain-maximum
        if energy_spent < curr_energy:
            gain = energy_spent*curr_value
            recurse(maximum, maximum, regain, values, curr_index+1, length, gainedSoFar+gain, ends)
    else:
        recurse(regain, maximum, regain, values, curr_index+1, length, gainedSoFar, ends)

    """











