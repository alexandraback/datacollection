#coding: utf8


s = '''\
3
5 4
2 1
4 20
'''

input = iter(s.splitlines(keepends=True))
import sys
out = sys.stdout
input = open('B-small-attempt0.in')
out   = open('B-small-attempt0.out', 'w')

#input = open('B-large.in')
#out   = open('B-large.out', 'w')

#input = open('B-large.in')
#out   = open('B-large.out', 'w')
#input = open('D-large-practice.in')
#out   = open('D-large-practice.out', 'w')



from itertools import combinations, permutations, combinations_with_replacement, product
from collections import defaultdict
from copy import deepcopy



def solve(B,M):
	S = [0]*B
	S[0] = 1
	for i in range(1,B):
		S[i] = sum(S[:i])
	if M>S[-1]:
		return []
	
	
	if M==S[-1]:
		ans =[[0]*B for _ in range(B)]
		for i in range(B-1):
			for j in range(i+1,B):
				ans[i][j] = 1
		return ans
	ans =[[0]*B for _ in range(B)]
	for i in range(B-1):
		for j in range(i+1,B):
			ans[i][j] = 1
	for i in range(B-1,-1,-1):
		if S[i]>M:
			ans[i][-1] = 0
			continue
		M-=S[i]
	return ans
	

CaseCnt = int(next(input))
for case in range(CaseCnt):
	B,M = map(int,next(input).split())
	ans = solve(B,M)
	
	#c = str(c).rjust(len(C), '0')
	#j = str(j).rjust(len(J), '0')
	if not ans:
		print('Case #%d:'%(case+1), 'IMPOSSIBLE', file=out)
	else:
		print('Case #%d:'%(case+1), 'POSSIBLE', file=out)
		for a in ans:
			print(*a, file=out)
