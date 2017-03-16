from Library import *
import math

def canMake(val, denom, c):
	remain = val
	for i in reversed(range(len(denom))):
		currc = 0
		while denom[i] <= remain and currc < c:
			remain -= denom[i]
			currc += 1
			if (remain == 0):
				return True
	return False


def solve(c, d, v, denom):
	countnew = 0
	for i in range(v):
		if (not canMake(i + 1, denom, c)):
			denom.append(i + 1)
			denom.sort()
			countnew += 1
	return countnew


lines = getLines("c.in")
out = []

for i in range(int(lines[0])):

	values = [int(l) for l in lines[i * 2 + 1].split()]
	denom = [int(l) for l in lines[i * 2 + 2].split()]
	res = solve(values[0], values[1], values[2], denom)

	out.append("Case #%d: %d"%(i + 1, res))
writeOutLines("out.txt", out)