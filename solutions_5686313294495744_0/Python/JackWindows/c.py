#!/usr/bin/python

import sys

if len(sys.argv) != 2:
	print "usage: ./c.py <input_file_name>"
	exit()

maximum = 0
tested = []

def dfs(data, num):
	global maximum, tested
	if num > maximum:
		maximum = num
	for title in data:
		if title in tested:
			continue
		d = data[:]
		d.remove(title)
		flag1 = False
		flag2 = False
		for t in d:
			if t[0] == title[0]:
				flag1 = True
			if t[1] == title[1]:
				flag2 = True
		if flag1 and flag2:
			tested.append(title)
			dfs(d, num + 1)

input_file_name = sys.argv[1]
if input_file_name[-3:] == ".in":
	output_file_name = input_file_name[:-3] + ".out"
else:
	output_file_name = input_file_name + ".out"

results = []
with open(input_file_name, 'r') as f:
	T = int(f.readline())
	for i in xrange(T):
		N = int(f.readline())
		data = []
		for j in xrange(N):
			S = f.readline()
			S = S[:-1]
			data.append(S.split(' '))
		maximum = 0
		tested = []
		dfs(data, 0)
		results.append(maximum)

with open(output_file_name, 'w') as f:
	for i in range(len(results)):
		output_string = "Case #%d: %d\n" % (i + 1, results[i])
		print output_string[:-1]
		f.write(output_string)
