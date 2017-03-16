#!/usr/bin/env python
import sys


def solve(j, p, s, k):
	s = min(s, k)

	out = ""

	c = 0
	for x in range(j):
		for y in range(p):
			for z in range(s):
				c += 1
				out += str(x+1) + " " + str(y + 1) + " " + str(z + 1) + "\n"

	return str(c) + "\n" + out

f = open(str(sys.argv[1])) 
out = open(str(sys.argv[2]), "w")

# Remove the first line of the input (which contains the length)
lines = [l for l in f]
lines = lines[1:]

# For each input line, find the potter number
count = 0
for i in lines:
	count += 1
	values = i.split()
	j = int(values[0])
	p = int(values[1])
	s = int(values[2])
	k = int(values[3])
	p = solve(j, p, s, k)
	out.write("Case #" + str(count) + ": " + p)
