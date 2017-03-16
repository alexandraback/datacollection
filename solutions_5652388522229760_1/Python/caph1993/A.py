import sys
from itertools import chain
sys.setrecursionlimit(1000000000)

in_file = "large"
sys.stdin = open(in_file+".in")
sys.stdout = open(in_file+".out","w")

def solve(x):
	s = set()
	for i in range(1,1000000):
		y = x*i
		for c in str(y): s.add(c)
		if len(s)==10 or i==100000: break
	ans = 'INSOMNIA' if i>=100000 else x*i
	return ans

ntc = int(input())

for tc in range(ntc):
	x = int(input().strip())
	ans = 'INSOMNIA' if x==0 else solve(x)
	print('Case #%d: '%(tc+1) + str(ans))
