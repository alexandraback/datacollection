




import numpy as np

import random

def get_domain(a,b,c):
	ret = []
	for x in range(a):
		for y in range(b):
			for z in range(c):
				ret.append((x,y,z))
	return ret


solution = []
search_cnt = 0

def domain_dfs(domain, K , history=[],mat = [[[0]*3 for _ in range(3)] for _ in range(3) ] ):

	global solution


	global search_cnt

	search_cnt += 1

	if search_cnt>=1000000:
		return


	sub_domain = []
	for x,y,z in domain:
		mat[0][x][y] +=1
		mat[1][y][z] +=1
		mat[2][x][z] +=1
		flag =True

		if mat[0][x][y]>K or mat[1][y][z]>K or mat[2][x][z]>K:
			flag = False
		if flag:
			sub_domain.append((x,y,z))
		mat[0][x][y] -=1
		mat[1][y][z] -=1
		mat[2][x][z] -=1

	if len(history)+ len(sub_domain) <= len(solution):
		return

	random.shuffle(sub_domain)
	if sub_domain == [] :
		if len(history)> len(solution):
			solution = history[:]
		return

	for x,y,z in sub_domain:
		mat[0][x][y] +=1
		mat[1][y][z] +=1
		mat[2][x][z] +=1
		history.append((x,y,z))
		domain_dfs([(a,b,c) for a,b,c in sub_domain if not(a==x and b==y and c==z)],K,history,mat)		
		history.pop()
		mat[0][x][y] -=1
		mat[1][y][z] -=1
		mat[2][x][z] -=1

	return


import sys
sys.setrecursionlimit(10000000)



T = int(raw_input())

for i in range(T):
	a,b,c,k = [int(x) for x in raw_input().split()]
	solution = []
	search_cnt = 0
	domain_dfs(get_domain(a,b,c),k,history=[],mat = [[[0]*3 for _ in range(3)] for _ in range(3) ])
	print 'Case #{}: {}'.format(i+1,len(solution))
	for line in solution:
		print ' '.join([str(x+1) for x in line])
