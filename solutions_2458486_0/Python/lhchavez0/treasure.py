#!/usr/bin/python

def freq(v):
	ans = [0] * 200
	for x in v:
		ans[x] += 1
	return ans

T = int(raw_input().strip())

for nCase in xrange(1, T+1):
	K,N = map(int, raw_input().strip().split())
	keys = freq([int(x) - 1 for x in raw_input().strip().split()])
	chests = []
	keyneeded = []
	keypresent = [False] * 200
	missing = [0] * 200
	G = [{} for x in xrange(200)]
	
	for i in xrange(len(keys)):
		if keys[i]:
			keypresent[i] = True
	
	for i in xrange(N):
		data = [int(x) - 1 for x in raw_input().strip().split()]
		keyneeded.append(data[0])
		missing[data[0]] += 1
		row = freq(data[2:])
		for i in xrange(len(row)):
			if row[i] > 0:
				G[data[0]][i] = True
				keypresent[i] = True
		row[data[0]] -= 1
		chests.append(row)
	
	visited = [False] * 200
	q = [i for i in xrange(len(keys)) if keys[i]]
	
	while q:
		x = q.pop()
		if visited[x]: continue
		visited[x] = True
		
		for k in G[x]:
			q.append(k)
	
	
	possible = all([keypresent[i] == visited[i] for i in xrange(len(keys))])
	possible = possible and all([keys[i] + sum([row[i] for row in chests]) >= 0 for i in xrange(len(keys))])
	
	if not possible:
		print "Case #%d: IMPOSSIBLE" % nCase
	else:
		def solve(i, n, sol, sofar, totalkeys, missing):
			if i == n:
				return sol
			else:
				for j in xrange(n):
					if j in sol: continue
					
					sofar2 = [sofar[k] + chests[j][k] for k in xrange(len(keys))]
					totalkeys2 = [totalkeys[k] - chests[j][k] for k in xrange(len(keys))]
					missing2 = missing[::]
					missing2[keyneeded[j]] -= 1
						
					if sofar[keyneeded[j]] > 0 and all([x >= 0 for x in sofar2]) and (i + 1 == n or any([x > 0 for x in sofar2])) and (missing2[keyneeded[j]] == 0 or sofar2[keyneeded[j]] > 0 or any([chests[k][keyneeded[j]] > 0 for k in xrange(n) if k not in sol])):
						ans = solve(i + 1, n, sol + (j,), sofar2, totalkeys2, missing2)
						if ans:
							return ans
				return False
		
		print "Case #%d: %s" % (nCase, " ".join([str(x + 1) for x in solve(0, N, (), keys[::], [sum([row[i] for row in chests]) for i in xrange(len(keys))], missing)]))

