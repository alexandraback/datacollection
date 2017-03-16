# coding: shift-jis

def dfs(x, r):
	for i in range(N):
		if D[x][i]:
			if P[i] == r: return True
			P[i] = r
			if dfs(i, r):
				return True
	return False
			

def solve(x):
	global P
	if sum(D[x]) > 1:
		P = [-1]*N
		return dfs(x, x)
	return False

if __name__=='__main__':
	import sys
	f = file(sys.argv[1])
	caseCnt = int(f.readline())
	for case in range(1, caseCnt+1):
		N = int(f.readline())
		D = [[0]*N for _ in range(N)]
		for i in range(N):
			a = map(int, f.readline().split()[1:])
			for ai in a:
				D[i][ai-1] = 1
		
		for i in range(N):
			ret = solve(i)
			if ret: break
		else:
			ret = False
		print "Case #%d:"%case, 'Yes' if ret else 'No'
