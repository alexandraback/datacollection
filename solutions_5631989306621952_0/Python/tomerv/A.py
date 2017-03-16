
def solve(s):
	res = ''
	for c in s:
		options = [res+c, c+res]
		res = sorted(options)[1]
	return res

t = int(input())
for i in range(t):
	tc = input()
	sol = solve(tc)
	print('Case #{}: {}'.format(i+1, sol))

