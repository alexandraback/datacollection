import sys
from itertools import chain
sys.setrecursionlimit(1000000000)

in_file = "small"
sys.stdin = open(in_file+".in")
sys.stdout = open(in_file+".out","w")

def solve(K,C,S):
	return list(range(1,K+1))

ntc = int(input())

for tc in range(ntc):
	K,C,S = map(int,input().strip().split(' '))
	ans = solve(K,C,S)
	print('Case #%d: '%(tc+1) + " ".join(map(str,ans)))
