#!/usr/bin/python

import sys
import numpy as np

if len(sys.argv) != 2:
	print "usage: ./b.py <input_file_name>"
	exit()

input_file_name = sys.argv[1]
if input_file_name[-3:] == ".in":
	output_file_name = input_file_name[:-3] + ".out"
else:
	output_file_name = input_file_name + ".out"

def calc(B, M):
	maximum = 2 ** (B - 2)
	if M > maximum:
		return 'IMPOSSIBLE'
	if M == maximum:
		binary = '{0:b}'.format(M - 1)
	else:
		binary = '{0:b}'.format(M)
	while len(binary) < B - 2:
		binary = '0' + binary
	if B == 2:
		binary = ''
	ret = ''
	if M == maximum:
		ret += '0' + binary + '1' + "\n"
	else:
		ret += '0' + binary + '0' + "\n"
	for i in range(1, B):
		ret += '0' * i + '0' + '1' * (B - i - 1) + "\n"
	ret = ret[:-1]
	ret = 'POSSIBLE' + "\n" + ret
	return ret

results = []
with open(input_file_name, 'r') as f:
	T = int(f.readline())
	for i in xrange(T):
		S = f.readline()
		S = S[:-1]
		B, M = S.split(' ')
		B = int(B)
		M = int(M)
		ret = calc(B, M)
		results.append(ret)

with open(output_file_name, 'w') as f:
	for i in range(len(results)):
		output_string = "Case #%d: %s\n" % (i + 1, results[i])
		print output_string[:-1]
		f.write(output_string)
