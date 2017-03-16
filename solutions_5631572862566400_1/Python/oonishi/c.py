#coding: utf8

#print(10*9*8*7*6*5*4*3*2*1)
#raise

s = '''\
4
4
2 3 4 1
4
3 3 4 1
4
3 3 4 3
10
7 8 10 10 9 2 9 6 3 3
'''

input = iter(s.splitlines(keepends=True))
import sys
out = sys.stdout
#input = open('C-small-attempt1.in')
#out   = open('C-small-attempt12.out', 'w')

input = open('C-large.in')
out   = open('C-large.out', 'w')

#input = open('B-large.in')
#out   = open('B-large.out', 'w')
#input = open('D-large-practice.in')
#out   = open('D-large-practice.out', 'w')



from itertools import combinations, permutations, combinations_with_replacement, product
from collections import defaultdict

#print(10*9*8*7*6*5*4*3*2*1)
#raise
#for 
#for s in permutations(range(10)):
#	#print(s)
#	pass
#raise
def solve(F):
	N = len(F)
	F = [f-1 for f in F]
	#print(F)
	#ans = N*2
	#for s in permutations(range(N)):
	#	
	#	val = 0
	#	for i in range(1, N-1):
	#		if s[i-1] != F[s[i]] and s[i+1] != F[s[i]]:
	#			val += 1
	#	if s[-1] != F[s[0]] and s[1] != F[s[0]]:
	#		val += 1
	#	if s[0] != F[s[-1]] and s[-2] != F[s[-1]]:
	#		val += 1
	#	if val < ans:
	#		print(s)
	#	#print(s, val)
	#	ans = min(val, ans)
	##raise
	ans = 0
	loved = [0]*N
	for f in F:
		loved[f] += 1
	#if 0 not in loved:
	#	return N
		
	cmax = 0
	L = [0]*N
	pair = set()
	for i in range(N):
		used = [0]*N
		x = i
		count = 0
		#path = []
		while not used[x]:
			used[x] = 1
			count += 1
			last = x
			#path += [x]
			x = F[x]
		
		if x == i:
			cmax = max(count, cmax)
		if F[last] == x and F[x] == last:
			#print(x, last, i)
			L[last] = max(L[last], count-1)
			L[x] = max(L[x], 1)
			if last>x:
				last,x = x,last
			pair.add((last, x))
	#print(L, pair)
	ans = cmax
	sm = 0
	for p in pair:
		sm +=  (L[p[0]] + L[p[1]])
	return max(ans, sm)
	

#print([1,1,1,1].index(0))
#raise
CaseCnt = int(next(input))
for case in range(CaseCnt):
	N, = map(int, next(input).split())
	*F, = map(int, next(input).split())
	ans = solve(F)

	print('Case #%d:'%(case+1), ans, file=out)
