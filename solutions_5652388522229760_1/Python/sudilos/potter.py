#!/usr/bin/env python
import sys

# Input: a non-negative number
# Output: a list of the digits in that number
def digits(n):
	out = []
	while(n > 0):
		d = n % 10
		out += [d]
		n = n / 10
	return out

# Input: a non-negative number n
# Output: the potter number for n, or -1 if INSOMNIA
def potter(n):
	# Zero is the only insomnia case
	if n == 0:
		return -1

	current = n # The number we are currently checking
	hits = [False for i in range(10)] # The digits that we have already seen

	while True:
		# Find the digits of current and add them to hits
		digs = digits(current)
		for i in digs:
			hits[i] = True

		# Check if we have seen all digits
		done = True
		for i in range(10):
			if not hits[i]:
				done = False
				break
		
		# If so, terminate
		if done:
			return current

		# Otherwise move on to the next number
		current += n

# UNIT TEST
#for i in range(1000001):
	#print i, potter(i)

# Get input/output files and open them
if(len(sys.argv) != 3):
	print "Usage ./potter.py <input> <output>"
	sys.exit(1)

f = open(str(sys.argv[1])) 
out = open(str(sys.argv[2]), "w")

# Remove the first line of the input (which contains the length)
lines = [l for l in f]
lines = lines[1:]

# For each input line, find the potter number
count = 1
for i in lines:
	p = potter(int(i))
	if p == -1:
		p = "INSOMNIA"
	out.write("Case #" + str(count) + ": " + str(p) + "\n")
	count += 1
