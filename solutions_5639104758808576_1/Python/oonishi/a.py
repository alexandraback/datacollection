#coding: cp932
# 2015 Qualification Problem A
input = iter('''
4
4 11111
1 09
5 110011
0 1
'''.splitlines()[1:])
import sys
output = sys.stdout

#input  = open(r'A-small-attempt0.in')
#output = open(r'A-small-attempt0.out', 'w')

input  = open(r'A-large.in')
output = open(r'A-large.out', 'w')

def solve(S):
	stood = S[0]
	
	res = 0
	for need,cnt in enumerate(S[1:], 1):
		if need > stood:
			add = need - stood
			stood += add
			res += add
		stood += cnt
	return res
		


caseCnt = int(next(input))
for caseNo in range(caseCnt):
	_,S = next(input).split()
	*S, = map(int, S)
	answer = solve(S)
	print('Case #%d:'%(caseNo+1), answer, file=output)
	
