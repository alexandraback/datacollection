#!/usr/bin/python

import sys

if len(sys.argv) != 2:
	print "usage: ./b.py <input_file_name>"
	exit()

input_file_name = sys.argv[1]
if input_file_name[-3:] == ".in":
	output_file_name = input_file_name[:-3] + ".out"
else:
	output_file_name = input_file_name + ".out"

results = []
with open(input_file_name, 'r') as f:
	T = int(f.readline())
	for k in range(T):
		S = f.readline()
		S = S[:-1]	#remove "\n" at the end of S
		ret = 0
		current_side = S[0]
		for i in range(1, len(S)):
			if S[i] == current_side:
				continue
			else:
				current_side = S[i]
				ret += 1
		if current_side == "-":
			ret += 1
		results.append(ret)

with open(output_file_name, 'w') as f:
	for i in range(len(results)):
		output_string = "Case #%d: %d\n" % (i + 1, results[i])
		print output_string[:-1]
		f.write(output_string)
