import os
import string
import sys


script = __file__
scriptPath = os.path.dirname(script)
scriptFile = os.path.basename(script)[0]
files = [f for f in os.listdir(scriptPath) if scriptFile in f and '.in' in f]
if '{}-large'.format(scriptFile) in str(files):
	size = 'large'
elif '{}-small'.format(scriptFile) in str(files):
	size = 'small'
elif '{}-test'.format(scriptFile) in str(files):
	size = 'test'
else:
	print('{}-test not found'.format(scriptFile))
	sys.exit()
latest = sorted(f for f in files if size in f)[-1][:-3]
f = '{}/{}'.format(scriptPath, latest)
I = open(f + '.in', 'r')
O = open(f + '.out', 'w')
print(f)
T = int(I.readline())



for x in range(T):
	C, J = I.readline().rstrip().split()
	c, j = '', ''
	leading = 1
	N = len(C)
	for i in range(N):
		a, b = C[i], J[i]
		if i < N - 1:
			a1, b1 = C[i+1], J[i+1]
		if i < N - 1 and ('?' in a+b and '?' not in a1+b1):
			if abs(int(a1) - int(b1)) > 5:
				c += [a, ['1', '0'][a1 > b1]][a == '?']
				j += [b, ['0', '1'][a1 > b1]][b == '?']
			else:
				c += [a, [b, '0'][b == '?']][a == '?']
				j += [b, [a, '0'][a == '?']][b == '?']
		else:
			if c == j:
				c += [a, [b, '0'][b == '?']][a == '?']
				j += [b, [a, '0'][a == '?']][b == '?']
			elif c > j:
				c += [a, '0'][a == '?']
				j += [b, '9'][b == '?']
			elif c < j:
				c += [a, '9'][a == '?']
				j += [b, '0'][b == '?']
		# print(x, c, j)

	y = '{} {}'.format(c, j)
	print(C, J, c, j)
	O.write('{}Case #{}: {}'.format(['', '\n'][x > 0], x+1, y))

I.close()
O.close()