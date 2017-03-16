#!/usr/bin/python

import sys
import numpy as np

if len(sys.argv) != 2:
	print "usage: ./a.py <input_file_name>"
	exit()

input_file_name = sys.argv[1]
if input_file_name[-3:] == ".in":
	output_file_name = input_file_name[:-3] + ".out"
else:
	output_file_name = input_file_name + ".out"

results = []
with open(input_file_name, 'r') as f:
	T = int(f.readline())
	for i in xrange(T):
		S = f.readline()
		S = S[:-1]
		ret = ''
		d = {'E': 0, 'F': 0, 'G':0, 'H': 0, 'I': 0, 'N': 0, 'O': 0, 'R': 0, 'S': 0, 'T': 0, 'U': 0, 'V': 0, 'W': 0, 'X': 0, 'Z': 0}
		char = ['ZERO', 'ONE', 'TWO', 'THREE', 'FOUR', 'FIVE', 'SIX', 'SEVEN', 'EIGHT', 'NINE']
		count = [0, 0, 0, 0, 0, 0, 0, 0, 0, 0]
		for c in S:
			d[c] += 1
		count[0] = d['Z']
		for i in xrange(count[0]):
			for c in char[0]:
				d[c] -= 1
		count[2] = d['W']
		for i in xrange(count[2]):
			for c in char[2]:
				d[c] -= 1
		count[6] = d['X']
		for i in xrange(count[6]):
			for c in char[6]:
				d[c] -= 1
		count[7] = d['S']
		for i in xrange(count[7]):
			for c in char[7]:
				d[c] -= 1
		count[5] = d['V']
		for i in xrange(count[5]):
			for c in char[5]:
				d[c] -= 1
		count[4] = d['U']
		for i in xrange(count[4]):
			for c in char[4]:
				d[c] -= 1
		count[3] = d['R']
		for i in xrange(count[3]):
			for c in char[3]:
				d[c] -= 1
		count[8] = d['T']
		for i in xrange(count[8]):
			for c in char[8]:
				d[c] -= 1
		count[1] = d['O']
		for i in xrange(count[1]):
			for c in char[1]:
				d[c] -= 1
		count[9] = d['E']
		for i in xrange(count[9]):
			for c in char[9]:
				d[c] -= 1
		for i in xrange(10):
			for j in xrange(count[i]):
				ret += str(i)
		results.append(ret)

with open(output_file_name, 'w') as f:
	for i in range(len(results)):
		output_string = "Case #%d: %s\n" % (i + 1, results[i])
		print output_string[:-1]
		f.write(output_string)
