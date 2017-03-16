# Getting the Digits

import fileinput
from collections import defaultdict

def contains(d, x):
	for c in x:
		if d[c] == 0: return False
	return True

def decrease(d, x):
	for c in x: d[c] -= 1

def asdigit(x):
	return ["ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"].index(x)

def solve(s):
	d = defaultdict(int)
	for c in s: d[c] += 1

	z = []
	for x in ["ZERO", "TWO", "SIX", "SEVEN", "EIGHT", "THREE", "FIVE", "FOUR", "ONE", "NINE"]:
		i = asdigit(x)
		while contains(d, x):
			decrease(d, x)
			z.append(i)

	return "".join(str(i) for i in sorted(z))

f = fileinput.input()
for t in range(int(f.readline().rstrip())):
	s = f.readline().rstrip()
	z = solve(s)
	print('Case #%s: %s' % (t + 1, z))
