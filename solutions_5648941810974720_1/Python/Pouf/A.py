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


from collections import Counter

for x in range(T):
	print(x)
	y = ''
	S = I.readline().rstrip()
	def gotcha(s, num):
		for l in num:
			s = s.replace(l, '', 1)
		return s, str(["ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"].index(num))
	while 'Z' in S:
		S, z = gotcha(S, 'ZERO')
		y += z
	while 'W' in S:
		S, z = gotcha(S, 'TWO')
		y += z
	while 'U' in S:
		S, z = gotcha(S, 'FOUR')
		y += z
	while 'X' in S:
		S, z = gotcha(S, 'SIX')
		y += z
	while 'G' in S:
		S, z = gotcha(S, 'EIGHT')
		y += z
	while 'F' in S:
		S, z = gotcha(S, 'FIVE')
		y += z
	while 'H' in S:
		S, z = gotcha(S, 'THREE')
		y += z
	while 'O' in S:
		S, z = gotcha(S, 'ONE')
		y += z
	while 'S' in S:
		S, z = gotcha(S, 'SEVEN')
		y += z
	while 'I' in S:
		S, z = gotcha(S, 'NINE')
		y += z
	y = ''.join(sorted(y))
	print(S, y)
	O.write('{}Case #{}: {}'.format(['', '\n'][x > 0], x+1, y))

I.close()
O.close()