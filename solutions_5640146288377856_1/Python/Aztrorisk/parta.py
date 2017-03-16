from Library import *
import math

def solve(row, col, width):
	nperrow = int(col / width)
	r = col % width
	sumc = nperrow * row
	if (r == 0):
		return sumc + width - 1
	else:
		return sumc + width

lines = getLines("ab.in")
out = []

for i in range(int(lines[0])):
	values = [int(l) for l in lines[i + 1].split()]
	res = solve(values[0], values[1], values[2])
	out.append("Case #%d: %d"%(i + 1, res))
writeOutLines("out.txt", out)