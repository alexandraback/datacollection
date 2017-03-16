#coding: utf8

s = '''\
7
CAB
JAM
CODE
ABAAB
CABCBBABC
ABCABCABC
ZXCASDQWE
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




from itertools import combinations, permutations, combinations_with_replacement, product
from collections import defaultdict


def solve(S):
	res = S[0]
	for c in S[1:]:
		if c + res <= res + c:
			res += c
		else:
			res = c + res
	return res
#print([1,1,1,1].index(0))
#raise
CaseCnt = int(next(input))
for case in range(CaseCnt):
	#N, = map(int, next(input).split())
	S = next(input).strip()
	print(S)
	ans = solve(S)

	print('Case #%d:'%(case+1), ans, file=out)
