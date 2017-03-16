def longestCycle(x):
	#used = [0] * len(x)
	ans = 0
	for start in range(len(x)):
		score = 0
		visited = [0]  *len(x)
		current = start
		while not visited[current]:
			visited[current] = True
			score += 1
			current = x[current]

		if current == start:
			ans = max(ans,score)
	return ans


def findPairs(x):
	ans = []
	used = set()
	for i in range(len(x)):
		if i not in used:
			j = x[i]
			if x[j] == i:
				ans.append((i,j))
				used.add(j)
	return ans


def f(x):
	pairs = findPairs(x)
	pairNum = [0] * len(x)
	count = 1
	for p in pairs:
		for i in p:
			pairNum[i] = count
			count += 1

	#print(pairNum)
	isLeaf = [1] * len(x)
	for i in x:
		isLeaf[i] = 0

	longestPaths = [0] * (len(pairs) * 2)
	#print(longestPaths)

	for start in range(len(x)):
		if isLeaf[start]:
			score = 0
			visited = [0] * len(x)
			current = start
			while not visited[current]:
				visited[current] = 1
				current = x[current]
				score += 1
				if pairNum[current]:
					i = pairNum[current] - 1
					if score > longestPaths[i]:
						longestPaths[i] = score
					break
	#print(longestPaths)
	return sum(longestPaths) + len(longestPaths)

def ans(x):
	return max(f(x), longestCycle(x))


	'''
	pairNum = [0] * len(x)
	for j, p in enumerate(pairs):
		for i in p:
			pairNum[i] = j + 1
	#return pairNum
	numPairs = len(pairs)
	found = []
	for i in range(numPairs + 1):
		found.append(set())

	usedInPath = []
	isLeaf = [0] * len(x)
	for i in x:
		isLeaf[i] = 1
	


	for start in range(len(x)):
		if (not isLeaf[start]):
			#score = 0
			#visited = [0] * len(x)
			path = set()
			current = start
			while current not in path:
				path.add(current)
				#score += 1
				current = x[current]
				if pairNum[current]:
					if len(path) > len(found[pairNum[current]]):
						found[pairNum[current]] = path
					#found[pairNum[current]].append(score)
					break
	
	used = [0] * len(x)
	for i in found:
		for j in i:
			used[j] = 1

	second = []
	for i in range(numPairs + 1):
		second.append(set())

	#print(isLeaf)
	#print(used)
	#print(pairNum)
	#print(x)

	for start in range(len(x)):
		if (not isLeaf[start] and not used[start]):
			path = set()
			current = start
			while current not in path:
				path.add(current)
				current = x[current]
				#print(current)
				if pairNum[current]:
					if len(path) > len(second[pairNum[current]]):
						second[pairNum[current]] = path
					#found[pairNum[current]].append(score)
					break
				if used[current]:
					break
	
	print(found, second)
	ans = 0
	for i in range(1, numPairs + 1):
		ans += 2 + len(found[i]) + len(second[i])
	return ans'''








n = int(input())
for i in range(n):
	t = int(input())
	y = list(map(lambda x: int(x) - 1,input().split()))
	x = ans(y)
	#print( f(y))
	print("Case #{0}: {1}".format(i+1, x))