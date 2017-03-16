#!/usr/bin/env python
import sys

def pancakes(s):
	out = 0

	# Initialize pancake stack
	stack = [i for i in s]	
	print "pancakes", stack
	last = stack[0]
	stack = stack[1:-1]

	# Loop through stack
	for i in stack:
		print i, last, out
		if i != last:
			out += 1
			last = i

	# Finally check if the last pancake was upside down
	if len(stack) > 0 and stack[-1] == '-' or len(stack) == 0 and last == '-':
		out += 1

	print "out", out
	return out

# Get input/output files and open them
if(len(sys.argv) != 3):
	print "Usage ./pancakes.py <input> <output>"
	sys.exit(1)

f = open(str(sys.argv[1])) 
out = open(str(sys.argv[2]), "w")

# Remove the first line of the input (which contains the length)
lines = [l for l in f]
lines = lines[1:]

# For each input line, find the potter number
count = 0
for i in lines:
	count += 1
	p = pancakes(i)
	out.write("Case #" + str(count) + ": " + str(p) + "\n")
