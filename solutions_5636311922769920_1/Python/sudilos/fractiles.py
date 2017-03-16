#!/usr/bin/env python
import sys

# Input: k, c - natural numbers
#		 indices - list of indices, each between 0 and k
# Outputs: a query number n such that a query on n returns L if and only if
# for every j in indices, the jth input letter is L
def query(k, c, indices):
	out = 0
	count = 1
	for i in indices:
		if (c - count) < 0:
			print "ERROR: too many indices in query"
			sys.exit(0)
		out += k ** (c - count) * i
		count += 1
	return out + 1 # The problem description counts from 1, whereas our formula
				   # counts from 0

# Input: k, c, s natural numbers
# Output: a list of at most s queries that determines whether an input letter was G, or -1
# if no such 
def fractile(k, c, s):

	# The input pattern indicies that have not yet been queried
	remaining = [i for i in range(k)] 
	# The output
	queries = []

	while len(remaining) > 0:
		this_query = remaining[:c]
		remaining = remaining[c:]
		queries += [query(k, c, this_query)]
		s = s - 1
		if(s < 0):
			return -1
		
	return queries




# Get input/output files and open them
if(len(sys.argv) != 3):
	print "Usage ./fractile.py <input> <output>"
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
	inputs =  i.split()
	p = fractile(int(inputs[0]), int(inputs[1]), int(inputs[2]))
	out.write("Case #" + str(count) + ":")
	if p == -1:
		out.write(" IMPOSSIBLE\n")
		continue
	for q in p:
		out.write(" " + str(q))
	out.write("\n")
