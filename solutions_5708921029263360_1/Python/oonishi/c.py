#coding: utf8


s = '''\
4
1 1 1 10
1 2 3 2
1 1 3 2
1 2 3 1
'''

input = iter(s.splitlines(keepends=True))
import sys
out = sys.stdout
input = open('C-small-attempt6.in')
out   = open('C-small-attempt6.out', 'w')

input = open('C-large.in')
out   = open('C-large.out', 'w')

#input = open('B-large.in')
#out   = open('B-large.out', 'w')
#input = open('D-large-practice.in')
#out   = open('D-large-practice.out', 'w')



from itertools import combinations, permutations, combinations_with_replacement, product
from collections import defaultdict
from copy import deepcopy


X = ((0,0,1),
(0,1,2),
(0,1,0),
(0,0,0),(0,0,2),(0,1,1))
def solve(J,P,S,K):
	#import pdb;pdb.set_trace()
	maxa = []
	
	*keys, = product(range(J), range(P), range(S))
	
	N = 1<<len(keys)
	ans = []
	for n in range(N):
		for j in range(len(keys)):
			if (n>>j)&1:
				ans
	
	keys = product(range(J), range(P))
	for xx in permutations(keys):
		

		#if xx == X:
		#	import pdb; pdb.set_trace()
		#k = K
		ans = []
		D = defaultdict(int)
		
		try:
			for j,p in xx:
				for s in range(S):
						k1 = (-1, p, s)
						k2 = ( j,-1, s)
						k3 = ( j, p,-1)
						if D[k1] >= K:
							raise StopIteration()
						if D[k2] >= K:
							raise StopIteration()
						if D[k3] >= K:
							raise StopIteration()
						#D.add(k1)
						#D.add(k2)
						#D.add(k3)
						#if k < 0:
						#	#print((j,p,s), D)
						#	raise StopIteration()
						D[k1] += 1
						D[k2] += 1
						D[k3] += 1
						#print(j,p,s)
						ans += [(j,p,s)]
		except StopIteration as s:
			pass

		if len(maxa) < len(ans):
			maxa = ans
			#print()
	return maxa

def solve(J,P,S,K):
	ans = []
	for k in range(min(K,S)):
		for j in range(J):
			for p in range(P):
				s = (p + j + k)%S
				ans += [(j,p,s)]
	return ans

CaseCnt = int(next(input))
for case in range(CaseCnt):
	J,P,S,K = map(int, next(input).split())
	ans = solve(J,P,S,K)
	
	#c = str(c).rjust(len(C), '0')
	#j = str(j).rjust(len(J), '0')
	
	print('Case #%d:'%(case+1), len(ans), file=out)
	for a in ans:
		a = [n+1 for n in a]
		print(*a, file=out)
