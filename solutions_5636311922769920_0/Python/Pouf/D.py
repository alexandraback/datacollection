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
latest = sorted(f for f in files if size in f)[0][:-3]
f = '{}/{}'.format(scriptPath, latest)
I = open(f + '.in', 'r')
O = open(f + '.out', 'w')
print(f)
T = int(I.readline())


for x in range(T):
	K, C, S = map(int, I.readline().split())
	y = ' '.join(str(i+1) for i in range(S))
	O.write('{}Case #{}: {}'.format(['', '\n'][x > 0], x+1, y))

I.close()
O.close()