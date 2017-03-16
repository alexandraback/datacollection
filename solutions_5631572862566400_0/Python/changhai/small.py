#debug 
def pr(*a):
	#return
	for x in a: print x,
	print
	
def maxChain(N, rev, a, b):
	visited = [0] * N
	rt = 0
	dist = 0
	visited[b] = 1
	que = [a]
	while que:
		newq = []
		found = 0
		for x in que:
			if visited[x]: continue
			else:
				found = 1
				for y in rev[x]:
					if not visited[y]:
						newq.append(y)
		if found: dist += 1
		#print newq, dist
		que=newq
	pr("dist", a, b, rev, dist)
	return dist

def findLoop(N, bff):
	rt = 0
	for i in range(N):
		cp = []
		cp.extend(bff)
		if cp[i] < 0: continue
		looplen = 0
		cur = i
		while cp[cur] >= 0:
			looplen += 1
			oldcur = cur
			cur = cp[oldcur]
			cp[oldcur] = -1
			if cur==i:
				rt = max(rt, looplen)
				#pr(i, looplen)
				break
	return rt
			
			
	

def solve(N, bff):
	rev = [ [] for i in range(N)]
	for i in range(N):
		a = i #a likes b
		b = bff[i]
		rev[b].append(a)
	noloop = 0
	for i in range(N):
		j = bff[i]
		if bff[j] == i and i < j:
			noloop += maxChain(N,rev,i,j)
			noloop += maxChain(N,rev,j,i)
	loop = findLoop(N, bff)
	return max(noloop, loop)
	
import sys
f = open(sys.argv[1])
out_fname = sys.argv[1][:-2] + "out"
out = open(out_fname,"w")
T = int(f.readline().strip())

for tc in range(1, T+1):
	N = int(f.readline().strip())
	bff = [int(x)-1 for x in f.readline().strip().split()]
	rt = solve(N, bff)
	pr("Case #%d: %s"%(tc, str(rt)))
	pr("="*20)
	print >>out, "Case #%d: %s"%(tc, str(rt))

out.close()