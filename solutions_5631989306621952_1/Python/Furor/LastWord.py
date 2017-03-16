

def solve(w):
	ans = w[0]
	for let in w[1:]:
		first = ''
		for a in ans:
			if a != let:
				first = a
				break
		if a == '' or let > a:
			ans = let + ans
		else:
			ans = ans + let
	return ans

t = int(input().strip())
for i in range(t):
	print('Case #{}: {}'.format(i + 1, solve(input().strip())))
