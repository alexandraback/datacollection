#coding: utf8
# 2015 Round3 Problem Problem A. Fairland
# https://code.google.com/codejam/contest/4254486/dashboard

s = '''\
5
-
-+
+-
+++
--+-
'''

input = iter(s.splitlines(keepends=True))
import sys
out = sys.stdout
input = open('B-small-attempt0.in')
out   = open('B-small-attempt0.out', 'w')
#input = open('D-large-practice.in')
#out   = open('D-large-practice.out', 'w')


X = 10**9 + 7


from itertools import combinations, permutations, combinations_with_replacement, product
from collections import defaultdict


CaseCnt = int(next(input))
for case in range(CaseCnt):
	s = next(input).strip()
	ans = 0
	#if s[-1] == '-':
	#	ans += 1
	s += '+'
	for i in reversed(range(len(s)-1)):
		if s[i] != s[i+1]:
			ans += 1
	#L = [0]
	#while L:
	#    p = L.pop()
	#    if S

	print('Case #%d:'%(case+1), ans, file=out)
