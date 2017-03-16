#!/usr/local/Cellar/python/2.7.9/Frameworks/Python.framework/Versions/2.7/bin/python2.7

import sys
from decimal import *
import itertools as it
from math import sqrt
from math import floor
from math import ceil
from math import log
from math import log10
import time
import random
import re
import string

inf = float('inf')

def solve(S):
	UPPER = 'ABCDEFGHIJKLMNOPQRSTUVWXYZ'
	counts = { c : S.count(c) for c in UPPER }

	digits = dict()

	digits[0] = counts['Z']
	for c in 'ZERO':
		counts[c] -= digits[0]

	digits[2] = counts['W']
	for c in 'TWO':
		counts[c] -= digits[2]

	digits[4] = counts['U']
	for c in 'FOUR':
		counts[c] -= digits[4]

	digits[5] = counts['F']
	for c in 'FIVE':
		counts[c] -= digits[5]

	digits[7] = counts['V']
	for c in 'SEVEN':
		counts[c] -= digits[7]

	digits[6] = counts['X']
	for c in 'SIX':
		counts[c] -= digits[6]

	digits[8] = counts['G']
	for c in 'EIGHT':
		counts[c] -= digits[8]

	digits[3] = counts['H']
	for c in 'THREE':
		counts[c] -= digits[3]

	digits[1] = counts['O']
	for c in 'ONE':
		counts[c] -= digits[1]

	digits[9] = counts['I']
	for c in 'NINE':
		counts[c] -= digits[9]

	out = ''
	for i in range(10):
		out += ('{}'.format(i)) * digits[i]

	return out

def main():
	infile = sys.argv[1]
	f = open(infile,'r')

	T = int(next_line(f))
	for t in range(T):
	    S = next_line(f).strip()
	    print 'Case #{}: {}'.format(t+1, solve(S))

	f.close()

def next_line(f):
    return f.readline().strip('\n')

main()
