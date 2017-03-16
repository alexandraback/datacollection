#coding: cp932
# 2015 Qualification Problem B
input = iter('''
5
1
3
4
1 2 1 2
1
4
4
8 1 8 6
1
9
'''.splitlines()[1:])
import sys
output = sys.stdout

input  = open(r'B-small-attempt6.in')
output = open(r'B-small-attempt6.out', 'w')

#input  = open(r'C-small-practice-2.in')
#output = open(r'C-large-practice.out', 'w')


def div(m,d):
	if d == 1:
		return (m,)
		
	if (m,d) in div.memo:
		return div.memo[(m,d)]
		
	x = (m+d-1)//d
	res = (x,) + div(m-x, d-1)
	div.memo[(m,d)] = res
	return res
div.memo = {}


def solve(D):
	if D == []:
		return 0
	D = sorted(D)
	N = len(D)
	
	cand = [D[-1]]
	m = D.pop()
	if m <= 3:
		return m
	for d in range(2,max(m//3+1,3)):
		add = div(m,d)
		res = solve(D+list(add))+d-1
		cand += [res]
	return min(cand)
		
	cnt = 0
	cand = [D[-1]]
	while D[-1] > 3:
		cnt += 1
		d = D.pop()
		new = (d+1)//2
		D += [new, d-new]
		D.sort()
		cand += [D[-1]+cnt]
	print(D)
	print(cand)
	return min(cand)

caseCnt = int(next(input))
for caseNo in range(caseCnt):
	d = int(next(input))
	*D, = map(int, next(input).split())
	answer = solve(D)
	print('Case #%d:'%(caseNo+1), answer, file=output)
	
