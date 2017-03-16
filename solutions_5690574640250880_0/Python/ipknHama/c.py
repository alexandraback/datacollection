'''
***10
23210

***1
*421
11

***10
**210
22100
00000

***10
**210
22100
00000

****1 (x)
23321

*****
23332

N*M

(N-2)*(M-2) ok

*****
*****
*****
***42
**310


...
...
..


...
...
...


16-5-4 
7-4-3

R >= a > c >= 2
0 <= b <= C-2
2*a + c*(C-2) + b

...................
...................
...................
.........**********
..*****************
..*****************
*******************
*******************
*******************

c = 0, 2, 3, ...

...................
...................
...................
..*****************
..*****************
*******************
*******************
*******************
'''
def solve(R,C,M,b):
	F = R*C-M
	if F%C == 0 and F/C>=2:
		for i in xrange(F/C):
			for j in xrange(C):
				b[i][j] = '.'
		b[0][0] = 'c'
		return True
	for c in xrange(R):
		if c == 1:
			continue
		for a in xrange(c+1,R+1):
			if a == 1:
				continue
			S = 2*a+(C-2)*c
			if S == F:
				for i in xrange(a):
					b[i][0] = b[i][1] = '.'
				for i in xrange(c):
					for j in xrange(2,C):
						b[i][j] = '.'
				b[0][0] = 'c'
				return True
			elif 0 <= F-S <= C-2 and c != 0:
				for i in xrange(a):
					b[i][0] = b[i][1] = '.'
				for i in xrange(c):
					for j in xrange(2,C):
						b[i][j] = '.'
				for j in xrange(2, F-S+2):
					b[c][j] = '.'
				b[0][0] = 'c'
				return True
	for r in range(3,R):
		for c in range(3, C):
			if r*c < F:
				continue
			f = r*c-F
			if f == r or 0 <= f <= r-2:
				for x in range(r):
					for y in range(c):
						b[x][y] = '.'
				for x in range(r-f,r):
					b[x][c-1] = '*'
				b[0][0]='c'
				return True



tn = input()
pn = 0
while tn:
	tn -= 1
	pn += 1
	print 'Case #%d:'%pn
	R,C,M = [int(x) for x in raw_input().split()]
	b = [['*' for i in xrange(C)] for j in xrange(R)]
	if M == R*C-1:
		b[0][0] = 'c'
		for i in xrange(R):
			print ''.join(b[i])
		continue
	if solve(R,C,M,b):
		for i in xrange(R):
			print ''.join(b[i])
		continue
	R,C=C,R
	b = map(list, zip(*b))
	if solve(R,C,M,b):
		R,C=C,R
		b = zip(*b)
		for i in xrange(R):
			print ''.join(b[i])
		continue
	print 'Impossible'


