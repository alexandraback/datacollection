import os
import string


thisPath = os.path.dirname(__file__)
thisFile = os.path.basename(__file__)[0]
f = '{}/{}-large'.format(thisPath, thisFile)
if not os.path.isfile(f + '.in'):
	f = '{}/{}-small'.format(thisPath, thisFile)
	if not os.path.isfile(f + '.in'):
		f = '{}/{}-test'.format(thisPath, thisFile)
I = open(f + '.in', 'r')
O = open(f + '.out', 'w')
print(f)
T = int(I.readline())


for x in range(T):
	print(x)
	S = list(I.readline().rstrip())
	print(S)
	y = 0
	while '-' in S:
		i = 1
		while i < len(S) and S[i] == S[0]:
			i += 1
		S = [['+', '-'][p=='+'] for p in reversed(S[:i])] + S[i:]
		y += 1


	O.write('Case #{}: {}{}'.format(x+1, y, ['\n', ''][x==T-1]))

I.close()
O.close()