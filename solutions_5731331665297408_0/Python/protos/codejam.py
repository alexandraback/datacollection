import itertools

def dfs(stk, now):
	#print stk, now
	stk.append(now[0])
	now = now[1:]

	if len(now) == 0:
		return True

	while len(stk) and not now[0] in link[stk[-1]]:
		stk.pop(-1)

	if len(stk) == 0:
		return False
	else:
		return dfs(stk, now)

tcn = int(raw_input())

for tc in range(1, tcn + 1):
	n, m = tuple([int(x) for x in raw_input().split()])

	name = []
	link = []
	for i in range(n):
		name.append(raw_input())
		link.append([])
	for i in range(m):
		x, y = tuple([int(x) for x in raw_input().split()])
		link[x - 1].append(y - 1)
		link[y - 1].append(x - 1)

	res = ''
	for i in itertools.permutations(range(n)):
		if dfs([], i):
			now = ''.join([name[i[j]] for j in range(n)])
			if res == '' or now < res:
				res = now;
	print 'Case #%d: %s' % (tc, res)