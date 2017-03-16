from parser import parse, maplist
import math
from decimal import *

parse_string = \
"""
<int t>
$t{
<int r> <int t>
>>> solve($r, $t)
}
>>> print_cases(list(%t))
"""

def solve(r, t):
	b = Decimal(4*r*r-4*r+8*t+1)
	a = int(b.sqrt())	
	if b - a*a < 0:
		a -= 1
	return 1 + int((a-2*r-3)/4)
    
def print_cases(l):
    for i, n in enumerate(l):
        print("Case #{0}: {1}".format(i + 1, n))

if __name__ == '__main__':
    parse(parse_string, globals())

