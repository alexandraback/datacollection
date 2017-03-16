import sys
from itertools import chain
sys.setrecursionlimit(1000000000)

in_file = "large"
sys.stdin = open(in_file+".in")
sys.stdout = open(in_file+".out","w")

q = [[[] for _ in range(101)] for _ in range(101)]

def pol(a,k):
	ans = 0
	for x in a:
		ans = ans*k + x
	return ans

def pre():
	for k in range(1,101):
		for c in range(1,101):
			n = 0
			while n<k:
				l = []
				for z in range(c):
					l += [ min( k-1, n ) ]
					n +=1
				q[k][c].append(pol(l,k)+1)

def solve(k,c,s):
	if s<len(q[k][c]):
		return ['IMPOSSIBLE']
	else:
		return q[k][c]

pre()
ntc = int(input())

for tc in range(ntc):
	K,C,S = map(int,input().strip().split(' '))
	ans = solve(K,C,S)
	print('Case #%d: '%(tc+1) + " ".join(map(str,ans)))
