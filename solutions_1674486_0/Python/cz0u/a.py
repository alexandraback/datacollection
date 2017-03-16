import sys

T = int(sys.stdin.readline().strip())

for c in range(T):
	N = int(sys.stdin.readline().strip())
	G = {}
	for i in range(N):	
		lines = [int(x) for x in sys.stdin.readline().split()]	
		G[i+1] = lines[1:]
	def find_acs(n):
		if G[n] == []:
			return []
		out = []
		for p in G[n]:
			acs = find_acs(p)
			if acs == []:
				out.append(p)
			else:
				out.extend(acs)
		return out
	ok = False
	for i in range(1, N+1):
		a = find_acs(i)
		if len(a) > len(set(a)):
			ok = True
			break

	print "Case #%d: %s"%(c+1, ok and "Yes" or "No") 

