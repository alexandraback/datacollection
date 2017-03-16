#!/usr/bin/python

import sys

if len(sys.argv) != 2:
	print "usage: ./d.py <input_file_name>"
	exit()

input_file_name = sys.argv[1]
if input_file_name[-3:] == ".in":
	output_file_name = input_file_name[:-3] + ".out"
else:
	output_file_name = input_file_name + ".out"

def draw(K, C, cols, cole):
	for pos in range(K):
		orig_s = 'L' * pos + 'G' + 'L' * (K - pos - 1)
		s = orig_s
		output_str = s
		for k in range(C):
			tmp = ''
			for c in s:
				if c == 'L':
					tmp += orig_s
				elif c == 'G':
					tmp += 'G' * K
			s = tmp
		output_str += ' ' + s[cols:cole+1]
		print output_str

def calcG():
	for K in range(2, 10):
		c = 1
		for i in range(1, K):
			c = c * (K) +1
		print c, (c-1)/(K-1)

def calcCG():
	C = 5
	for K in range(C, 10):
		c = 1
		for i in range(1, C):
			c = c * K +1
		print c, (c+(K-C)-1)/(K-1)

def calc(C, K):
	if K == 1:
		return 1
	if K < C:
		C = K
	count_G = 1
	for i in range(1, C):
		count_G = count_G * K +1
	return (count_G + K - C - 1) / (K - 1)


results = []
with open(input_file_name, 'r') as f:
	T = int(f.readline())
	for k in range(T):
		tmp = f.readline().split(' ')
		K = int(tmp[0])
		C = int(tmp[1])
		S = int(tmp[2])
		info_needed = max(K - C + 1, 1)
		if S < info_needed:
			results.append('IMPOSSIBLE')
		else:
			start_index = calc(C, K)
			ret = range(start_index, start_index + info_needed)
			results.append(ret)

with open(output_file_name, 'w') as f:
	for i in range(len(results)):
		output_string = "Case #%d:" % (i + 1)
		if results[i] == 'IMPOSSIBLE':
			output_string += " IMPOSSIBLE\n"
		else:
			for j in range(len(results[i])):
				output_string += " %d" % results[i][j]
			output_string += "\n"
		print output_string[:-1]
		f.write(output_string)
