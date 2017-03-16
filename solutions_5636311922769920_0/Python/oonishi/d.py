#coding: utf8
# 2015 Round3 Problem Problem A. Fairland
# https://code.google.com/codejam/contest/4254486/dashboard

s = '''\
5
2 3 2
1 1 1
2 1 1
2 1 2
3 2 3
'''

input = iter(s.splitlines(keepends=True))
import sys
out = sys.stdout
input = open('D-small-attempt1.in')
out   = open('D-small-attempt1.out', 'w')

#input = open('B-large.in')
#out   = open('B-large.out', 'w')
#input = open('D-large-practice.in')
#out   = open('D-large-practice.out', 'w')


X = 10**9 + 7


from itertools import combinations, permutations, combinations_with_replacement, product
from collections import defaultdict


#LLL LLLLLLLLL
#GLL GGGGLLGLL
#LGL LGLGGGLGL
#LLG LLGLLGGGG
#GGL GGGGGGGGL
#GLG GGGGLGGGG
#LGG LGGGGGGGG
#GGG GGGGGGGGG


#GLLL GGGGGLLLGLLLGLLL
#LGLL LGLLGGGGLGLLLGLL
#LLGL LLGLLLGLGGGGLLGL
#LLLG LLLGLLLGLLLGGGGG
#GGLL GGGGGGGGGGLLGGLL
#LGGL LGGLGGGGGGGGLGGL
#LLGG LLGGLLGGGGGGGGGG
#GLGL
#LGLG
#GLLG
#GGGL
#GGLG
#GLGG
#LGGG
#LLLL
#GGGG

def solve(K,C,S):
	ans = []
	#used = [0]*K
	c = C
	n = 0
	k = 0
	for s in range(S):
		n = 0
		for c in range(C):
			n = n*K + k
			k += 1
			if k == K:
				break
		ans += [n+1]
		if k == K:
			return ans
			
		
	return []
#print([1,1,1,1].index(0))
#raise
CaseCnt = int(next(input))
for case in range(CaseCnt):
	K,C,S = map(int, next(input).split())
	print(K,C,S)
	ans = solve(K,C,S)
	if not ans: ans = ['IMPOSSIBLE']
	#if s[-1] == '-':
	#	ans += 1
	#L = [0]
	#while L:
	#    p = L.pop()
	#    if S

	print('Case #%d:'%(case+1), *ans, file=out)
