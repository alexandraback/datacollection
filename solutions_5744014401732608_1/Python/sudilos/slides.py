#!/usr/bin/env python
import sys

def bd(m):
	out = []
	while(m > 0):
		if m % 2 == 0:
			out += [0]
		else:
			out += [1]
		m /= 2
	return list(reversed(out))

def pad(b, s):
	if len(s) < b:
		s = [0 for i in range(b - len(s))] + s
	return s

def s(b, m):
	if(m > 2** (b-2)):
		return "IMPOSSIBLE\n"

	out = "POSSIBLE\n"
	if (m == 2**(b-2)):
		out += "".join(["0"] + ["1" for i in range(b-1)]) + "\n"
	else:
		out += "".join([str(x) for x in pad(b, bd(2*m))]) + "\n"

	t = b - 1
	while(t > 0):
		out += "".join([str(x) for x in pad(b, bd(2**(t-1)-1))]) + "\n"
		t -= 1

	return out

# Get input/output files and open them
if(len(sys.argv) != 3):
	print "Usage: [program]  <input> <output>"
	sys.exit(1)

f = open(str(sys.argv[1])) 
out = open(str(sys.argv[2]), "w")

# Remove the first line of the input (which contains the length)
lines = [l for l in f]
lines = lines[1:]

count = 0
for i in lines:
	count += 1
	values = i.split()
	b = int(values[0])
	m = int(values[1])
	p = s(b, m)
	out.write("Case #" + str(count) + ": " +   p)
