import sys
sys.setrecursionlimit(10000)
def dfs(x,M,s):
	for y in M[x]:
		if s[y]: return True
		else:
			s[y]=1
			if dfs(y,M,s): return True
	return False
for T in range(input()):
	N=input()
	M={}
	for n in range(N):
		s=map(lambda x:int(x)-1,raw_input().split())
		s=s[1:]
		M[n]=s
		#print s
	f=False
	for n in range(N):
		if len(M[n])>1:
			s=[0]*N
			if dfs(n,M,s): 
				f=True
				break
	if f:
		print "Case #%d: Yes" % (T+1)
	else:
		print "Case #%d: No" % (T+1)
	#print "Case #%d: %s" % (N+1, " ".join(m))
	