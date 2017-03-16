#coding: utf8


s = '''\
3
16
AZ DM
PL DM
LO EZ
RJ FY
PL NN
RX EZ
RX NN
RX OC
PI OC
PL PY
RJ RU
RX RU
LO SV
WE SV
DL TT
RJ TT
3
HYDROCARBON COMBUSTION
QUAIL BEHAVIOR
QUAIL COMBUSTION
3
CODE JAM
SPACE JAM
PEARL JAM
2
INTERGALACTIC PLANETARY
PLANETARY INTERGALACTIC
'''

input = iter(s.splitlines(keepends=True))
import sys
out = sys.stdout
input = open('C-small-attempt2.in')
out   = open('C-small-attempt2.out', 'w')

#input = open('B-large.in')
#out   = open('B-large.out', 'w')

#input = open('B-large.in')
#out   = open('B-large.out', 'w')
#input = open('D-large-practice.in')
#out   = open('D-large-practice.out', 'w')



from itertools import combinations, permutations, combinations_with_replacement, product
from collections import defaultdict
from copy import deepcopy

def test(R):
	for i,(r1,r2) in enumerate(R):
		if r1>1 and r2>1:
			return i
			
	return -1
		
	
def solve(S):
	F = defaultdict(int)
	L = defaultdict(int)
	for s1,s2 in S:
		F[s1] += 1
		L[s2] += 1
		
	S.sort(key=lambda s:max(F[s[0]], L[s[1]]), reverse=True)
	res = 0
	while S:
		s1,s2 = S[0]
		print(S[0], F[s1], L[s2])
		if F[s1] == 1 or L[s2] == 1:
			pass
		else:
			res += 1
			F[s1] -= 1
			L[s2] -= 1
		S = S[1:]
		S.sort(key=lambda s:max(F[s[0]], L[s[1]]), reverse=True)
	print([min(F[s[0]], L[s[1]]) for s in S])
	return res
		
		
	
	
	
CaseCnt = int(next(input))
for case in range(CaseCnt):
	N = int(next(input))
	S = []
	for i in range(N):
		s1,s2 = next(input).split()
		S +=[(s1,s2)]

	#import pdb;pdb.set_trace()
	ans = solve(S)
	
	#c = str(c).rjust(len(C), '0')
	#j = str(j).rjust(len(J), '0')
	
	print('Case #%d:'%(case+1), ans, file=out)
