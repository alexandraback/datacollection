'''
CodeJam 2013 Round 1A
Problem B: Manage Your Energy
Author: Jon Eisen

This solution uses [pycodejam](http://github.com/yanatan16/pycodejam).
'''
from codejam import CodeJam, parsers
from codejam.helpers import memoize
from math import ceil

def solve(params, ns):
	E, r, n = params
	maxn = max(ns)

	@memoize
	def best(e, *rest):
		if len(rest) == 0:
			return 0
		else:
			t, rest = rest[0], rest[1:]
			if t == maxn:
				return e * t + best(r, *rest)

			all = [x * t + best(min(e-x+r,E), *rest) for x in reversed(xrange(e+1))]
			return max(all)

	return best(E, *ns)

if __name__ == "__main__":
	CodeJam(parsers.ints, solve).main()