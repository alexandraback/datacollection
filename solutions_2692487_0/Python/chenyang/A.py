from parser import *

parse_string = \
"""
<int t>
$t{
<int a> <int n>
<str s>
>>> solve($a, maplist($s, int))
}
>>> print_cases(list(%t))
"""

def solve(a, l):
	return search(a, l)

def search(a, l):
	if l == []:
		return 0
	m = min(l)
	l.remove(m)
	if m < a:
		return search(a + m, l[:])
	elif m < 2*a - 1:
		return 1 + search(m + 2*a - 1, l[:])
	else:
		if a == 1:
			return 1 + search(a, l[:])
		return 1 + min(search(2*a - 1, l[:] + [m]), search(a, l[:]))

	
def print_cases(l):
    for i, n in enumerate(l):
        print("Case #{0}: {1}".format(i + 1, n))

if __name__ == '__main__':
    parse(parse_string, globals())

