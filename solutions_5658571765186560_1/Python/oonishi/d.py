#coding: cp932
# 2015 Qualification Problem D
input = iter('''
5
2 1 2
2 1 3
4 4 1
2 2 2
3 2 3
'''.splitlines()[1:])
import sys
output = sys.stdout

#input  = open(r'D-small-attempt3.in')
#output = open(r'D-small-attempt3.out', 'w')

input  = open(r'D-large.in')
output = open(r'D-large.out', 'w')


def solve(X,R,C):
	if X>=7:
		return 'RICHARD'
	if R*C%X:
		return 'RICHARD'
	if X>2 and R+C-1<=X:
		return 'RICHARD'
	if R>C:
		C,R=R,C
		
	if R<(X+1)//2:
		return 'RICHARD'
		
	if X-R+1 >= R:
		C,R = R,C
	
	if X<C: return 'GABRIEL'
	
	K = X-C
	#import pdb;pdb.set_trace()
	if K == 0:
		if C*(R-1) % X == 0:
			return 'GABRIEL'
		for r in range(1,R-1):
			if C*r % X == 0:
				return 'GABRIEL'
			if C*(R-r-1) % X == 0:
				return 'GABRIEL'
		return 'RICHARD'
	
	for k1 in range(K+1):
		k2 = K-k1
		for r in range(k1,R-k2):
			n = C*r - k1
			m = C*(R-r-1) - k2
			
			if n%X == 0 and m%X == 0:
				break
		else:
			return 'RICHARD'
	return 'GABRIEL'
import time
st = time.time()
caseCnt = int(next(input))
for caseNo in range(caseCnt):
	X,R,C = map(int, next(input).split())
	answer = solve(X,R,C)
	print(X,R,C)
	print('Case #%d:'%(caseNo+1), answer, file=output)
	
print(time.time()-st)