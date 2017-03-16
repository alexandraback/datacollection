def _mul (a, b):
	if a == "t": return b
	if b == "t": return a
	if a == b: return "T"

	if (a, b) == ("i", "j"): return "k"
	if (a, b) == ("j", "i"): return "K"

	if (a, b) == ("i", "k"): return "J"
	if (a, b) == ("k", "i"): return "j"

	if (a, b) == ("j", "k"): return "i"
	if (a, b) == ("k", "j"): return "I"

def mul (a, b):
	minus = False

	if a.isupper(): minus = not minus
	if b.isupper(): minus = not minus

	res = _mul(a.lower(), b.lower())

	if minus:
		if res.isupper(): return res.lower()
		else: return res.upper()

	return res

import itertools
from functools import reduce

def compute (data, times):
	seeni = False
	seenk = False

	for a in itertools.accumulate(data*min(times, 6), mul):
		if a == "i": seeni = True
		if seeni and a == "k":
			seenk = True
			break

	if not seenk: return False

	block = reduce (mul, data)
	i = 1
	res = block

	while res != "t":
		res = mul(res, block)
		i += 1
	
	times = times % i

	if reduce(mul, block*times, "t") != "T": return False
	return True


T = int(input())

for case in range(T):
	times = int(input().strip().split()[1])
	data = input().strip()

	can = "YES" if compute(data, times) else "NO"

	print ("Case #{}: {}".format(case+1, can))
