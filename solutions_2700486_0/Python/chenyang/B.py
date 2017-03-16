from parser import *
import math

parse_string = \
"""
<int t>
$t{
<int n> <int x> <int y>
>>> solve($n, $x, $y)
}
>>> print_cases(list(%t))
"""

seq = lambda b: 2*b*b + 3*b + 1

def solve(n, x, y):
	x = abs(x)
	b = (x + y) // 2 - 1
	before = seq(b)
	a = n - before
	if a < y + 1:
		return 0.0
	if x == 0 and n < seq(b+1):
		return 0.0	
	if a >= x+2*y+1:
		return 1.0
	c = 0
	for i in range(y+1):
		c += nCr(a, i)
	return 1 - 0.5**a * c

def nCr(n,r):
    f = math.factorial
    return f(n) / f(r) / f(n-r)
    
def print_cases(l):
    for i, n in enumerate(l):
        print("Case #{0}: {1}".format(i + 1, n))

if __name__ == '__main__':
    parse(parse_string, globals())

