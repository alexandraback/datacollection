
def solve(x, parent):
	if not parent[x]:
		return [x]

	return reduce(lambda u, v: u + solve(v, parent), parent[x], [])

T = int(raw_input())
for t in range(T):
	N = int(raw_input())
	parent = []
	for i in range(N):
		parent.append([int(x) - 1 for x in raw_input().split()[1:]])

	res = False
	for i in range(N):
		s = solve(i, parent)
		if len(set(s)) < len(s):
			res = True
			break

	print 'Case #{}: {}'.format(t+1, 'Yes' if res else 'No')
