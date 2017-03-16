#coding: utf8
# 2015 Round3 Problem Problem A. Fairland
# https://code.google.com/codejam/contest/4254486/dashboard

s = '''\
5
0
1
2
11
1692
'''

input = iter(s.splitlines(keepends=True))
import sys
out = sys.stdout
#input = open('A-small-attempt0.in')
#out   = open('A-small-attempt0.out', 'w')

input = open('A-large.in')
out   = open('A-large.out', 'w')

#input = open('B-large.in')
#out   = open('B-large.out', 'w')
#input = open('D-large-practice.in')
#out   = open('D-large-practice.out', 'w')


X = 10**9 + 7


from itertools import combinations, permutations, combinations_with_replacement, product
from collections import defaultdict


def solve(N):
	if N == 0:
		return 'INSOMNIA'
	used = [0]*10
	n = 0
	while 0 in used:
		n += N
		for c in str(n):
			used[int(c)] = 1
	return n
#print([1,1,1,1].index(0))
#raise
CaseCnt = int(next(input))
for case in range(CaseCnt):
	N, = map(int, next(input).split())
	print(N)
	ans = solve(N)

	print('Case #%d:'%(case+1), ans, file=out)
