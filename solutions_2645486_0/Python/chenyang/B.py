from parser import parse, maplist

parse_string = \
"""
<int t>
$t{
<int e> <int r> <int n>
<str a>
>>> solve($e, $r, maplist($a, int))
}
>>> print_cases(list(%t))
"""

def solve(e, r, li):
	maxe = e
	maxl = max(li)
	def dfs(e, r, li):
		if li == []:
			return 0
		elif li[0] == maxl:
			return dfs(min(r, maxe), r, li[1:]) + e * li[0]
		else:			
			l = [dfs(min(e-i+r, maxe), r, li[1:]) + i*li[0]
				 for i in range(e+1)]
			return max(l)
	return dfs(e, r, li)
    
def print_cases(l):
    for i, n in enumerate(l):
        print("Case #{0}: {1}".format(i + 1, n))

if __name__ == '__main__':
    parse(parse_string, globals())

