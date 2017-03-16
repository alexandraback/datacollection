def doit(left, keys):
	if left == 0: return True
	if mem[left] is not None: return mem[left] != -1
	mem[left] = -1
	for i in xrange(N):
		if ((left >> i) & 1) == 0: continue
		key = need[i]
		if keys[key] == 0: continue
		keys[key] -= 1
		for k in bonus[i]:
			keys[k] += 1
		ok = doit(left ^ (1 << i), keys)
		for k in bonus[i]:
			keys[k] -= 1
		keys[key] += 1
		if not ok: continue
		mem[left] = i
		return True
	return False

def solve():
	global N, mem, need, bonus
	N = map(int, raw_input().split())[1]
	mem = [None] * (1 << N)
	keys = [0] * 200
	for k in map(int, raw_input().split()):
		keys[k - 1] += 1
	need = []
	bonus = []
	for i in xrange(N):
		a = map(int, raw_input().split())
		need.append(a[0] - 1)
		bonus.append([x - 1 for x in a[2:]])

	if not doit((1 << N) - 1, keys): return "IMPOSSIBLE"
	res = []
	left = (1 << N) - 1
	while left:
		next = mem[left]
		res.append(next)
		left ^= 1 << next
	return ' '.join([str(x + 1) for x in res])

for i in xrange(input()):
	print "Case #%d: %s" % (i + 1, solve())
