
def get_candidates(bffs):
	ret = []
	for i in range(len(bffs)):
		for j in range(i+1, len(bffs)):
			if bffs[i] == j and bffs[j] == i:
				ret.append((i, j))
	return ret

def longest(n, dontgo, edges):
	print 'longest', n, dontgo
	ret = 1
	for nb in edges[n]:
		if nb != dontgo:
			ret = max(ret, longest(nb, dontgo, edges) + 1)
	return ret

# def dfs(n, starting, visited, edges):
# 	next = edges[n]
# 	if starting in visited


f = open('c.small.in')
fout = open('c.out', 'w')

numCases = int(f.readline().strip())

for numCase in range(numCases):
	print 'CASE: {}'.format(numCase+1)
	N = int(f.readline().strip())
	bffs = [None] * N
	reverse_bffs = []
	for i in range(N):
		reverse_bffs.append([])

	ss = f.readline().split()
	for i in range(N):
		bffs[i] = int(ss[i]) - 1
		reverse_bffs[int(ss[i]) - 1].append(i)

	# print bffs
	# print reverse_bffs

	#case 1
	case1max = 0
	candidates = get_candidates(bffs)
	len_candidates = len(candidates)
	for (c_x, c_y) in candidates:		
		# print c_x, c_y
		print c_x
		d1 = longest(c_x, c_y, reverse_bffs)
		print c_y
		d2 = longest(c_y, c_x, reverse_bffs)
		case1max = max(case1max, d1+d2 + 2 * (len_candidates-1) )
		print c_x, d1
		print c_y, d2
		print case1max

	case2max = 0
	for n in range(0, N):
		if len(reverse_bffs[n]) == 0:
			continue
		cnt = 1
		cur = n
		visited = set()
		visited.add(cur)
		while True:
			next = bffs[cur]
			if next == n:
				break
			if next in visited:
				cnt = 0
				break
			visited.add(next)
			cur = next
			cnt += 1
		print 'cycle starting n:', n, cnt
		case2max = max(case2max, cnt)

		# visited = set()
		# visited.add(n)
		# d = dfs(n, n, visited, bffs)
		# print n, d
		# case2max = max(case2max, d)


	#case 2
	# for node in range(1, N+1):
	# print ' '.join(result)
	print 'case1max', case1max, 'case2max', case2max
	fout.write('Case #{}: {}\n'.format(numCase+1, max(case1max, case2max)))



fout.close()



