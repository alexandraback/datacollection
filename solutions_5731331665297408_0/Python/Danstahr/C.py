import itertools

def validpermutation(permutation, edges):
	stack = [permutation[0]]
	for item in permutation[1:]:		
		while True:
			if not stack:
				return False
			elif not item in edges[stack[-1]]:
				stack = stack[:-1]
			else:
				break
		stack.append(item)
	return True
		
		

t = int(raw_input())
for case in range(1, t+1):
	n, m = map(int, raw_input().split())
	zips = []
	neibs = []
	for i in range(n):
		neibs.append([])
	for i in range(n):
		zips.append(raw_input())
	for i in range(m):
		u, v = map(int, raw_input().split())
		neibs[u-1].append(v-1)
		neibs[v-1].append(u-1)
	#print neibs
	result = None
	for permutation in itertools.permutations(range(n)):
		if validpermutation(permutation, neibs):
			res = ""
			for i in permutation:
				res += zips[i]
			res = int(res)	
			if result is None:
				result = res
			else:
				result = min(result, res)
	print "Case #%d: %d" % (case, result)
				
			
	
	
