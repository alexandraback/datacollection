from itertools import permutations
from itertools import combinations

def is_good(tc, circle):
	n = len(circle)
	# print(tc, circle)
	for i in range(n):
		kid = circle[i]
		# print('   ', i, kid, tc[kid] ,[circle[(i-1+n)%n], circle[(i+1) % n]])
		if tc[kid] not in [circle[(i-1+n)%n], circle[(i+1) % n]]:
			# print('bad')
			return False
	return (len(set(circle)) == len(circle))

"""
def solve(tc):
	n = len(tc)
	res = n
	while True:
		for comb in combinations(list(range(n)), res):
			# print('xxx', comb)
			for perm in permutations(comb):
				# print(perm)
				if is_good(tc, list(perm)):
					return res
		res -= 1
"""

def maxpath(tc, kid):
	n = len(tc)
	path = [kid]
	while kid >= 0 and tc[kid] not in path:
		kid = tc[kid]
		path += [kid]
	return path

def maxpaths(tc):
	n = len(tc)
	return [maxpath(tc, kid) for kid in range(n)]

def subpaths(p):
	res = []
	n = len(p)
	for i in range(n):
		for j in range(i, n):
			res += [p[i:j+1]]
	return res

def solve(tc):
	res = 0
	n = len(tc)
	for kid in range(n):
		p = maxpath(tc, kid)
		if is_good(tc, p):
			res = max([res, len(p)])
	for k1 in range(n):
		for k2 in range(n):
			if k1 == k2:
				continue
			p1 = maxpath(tc, k1)
			p2 = maxpath(tc, k2)[::-1]
			# print(p1, p2)
			if p1[-2:] == p2[:2]:
				p = p1[:-2] + p2
				# print(' ', p)
				if is_good(tc, p):
					res = max([res, len(p)])
	return res	

t = int(input())
for i in range(t):
	n = int(input())
	tc = list(map(lambda x: int(x)-1, input().split()))
	sol = solve(tc)
	print('Case #{}: {}'.format(i+1, sol))

