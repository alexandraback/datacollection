import sys
from itertools import chain
sys.setrecursionlimit(1000000000)

in_file = "small"
sys.stdin = open(in_file+".in")
sys.stdout = open(in_file+".out","w")

def solve(s):
	ans = s.count('+-')
	ans += s.count('-+')
	ans += (s[-1]=='-')
	return ans

ntc = int(input())

for tc in range(ntc):
	x = input().strip()
	ans = solve(x)
	print('Case #%d: '%(tc+1) + str(ans))
