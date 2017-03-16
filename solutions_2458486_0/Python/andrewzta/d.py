t = int(input())

for test in range(1, t + 1):
	cnt = [0] * 201
	k, n = [int(x) for x in input().split()]
	for i in [int(x) for x in input().split()]:
		cnt[i] += 1

	keyt = []
	inside = []
	for i in range(n):
		vv = [int(x) for x in input().split()]
		keyt += [vv[0]]
		inside += [vv[2:]]
	
	go = [set() for i in range(2 ** n)]
	queue = [0]
	h = 0
	was = set()
	z = [i for i in cnt]
	while h < len(queue):
		p = queue[h]
		h += 1
		for j in range(n):
			if (p & (1 << j)) != 0:
				z[keyt[j]] -= 1
				for t in inside[j]:
					z[t] += 1
		for j in range(n):
			if ((p & (1 << j)) == 0) and (z[keyt[j]] > 0):
				q = p | (1 << j)
				if not (q in was):
					was.add(q)
					go[p].add(q)
					queue += [q]
		for j in range(n):
			if (p & (1 << j)) != 0:
				z[keyt[j]] += 1
				for t in inside[j]:
					z[t] -= 1

	if not (2 ** n - 1 in was):
		print("Case #" + str(test) + ": IMPOSSIBLE")
		continue
		
	fr = [set() for i in range(2 ** n)]
	for p in range(len(go)):
		for q in go[p]:
			fr[q].add(p)

	queue = [2 ** n - 1]
	h = 0	
	good = set()
	good.add(2 ** n - 1)
	while h < len(queue):
		p = queue[h]
		h += 1
		for q in fr[p]:
			if not q in good:
				good.add(q)
				queue += [q]

	cur = 0
	ans = []
	while cur != 2 ** n - 1:
		for j in range(n):
			nxt = cur | (1 << j)
			if nxt in go[cur] and nxt in good:
				ans += [j]
				cur = nxt
				break

	print("Case #" + str(test) + ": " + " ".join([str(x + 1) for x in ans]))
