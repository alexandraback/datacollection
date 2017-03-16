from string import lowercase
import sys

rl = sys.stdin.readline
T = int(rl())

for i in range(0, T):
	N = int(rl())
	route = []
	mem = [None]
	for j in range(0, N):
		inp = map(int, rl().split(' '))
		
		route.append([])
		for k in range(0, inp[0]):
			route[j].append(inp[k+1])
			
		mem.append(None)
	
	def solvefor(t):
		if not mem[t] == None:
			return mem[t]
		
		mem[t] = []
		for par in route[t - 1]:
			mem[t].append(par)
			mem[t].extend(solvefor(par))
				
		return mem[t]
	
	def solve():
		for i in range(0, N):
			res = solvefor(i)
			if len(set(res)) != len(res):
				return True
			
		return False
	
	if solve():
		print 'Case #%d: Yes' % (i+1)
	else:
		print 'Case #%d: No' % (i+1)
