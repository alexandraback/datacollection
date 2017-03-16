import os
import string


this = os.path.dirname(__file__)
f = '{}/large'.format(this)
if not os.path.isfile(f + '.in'):
	f = '{}/small'.format(this)
	if not os.path.isfile(f + '.in'):
		f = '{}/test'.format(this)
i = open(f + '.in', 'r')
o = open(f + '.out', 'w')
T = int(i.readline())


for t in range(T):
	left = set(string.digits)
	iN = N = int(i.readline().rstrip())
	left -= set(str(N))
	while left:
		iN += N
		left -= set(str(iN))
		if iN == N:
			result = 'INSOMNIA'
			break
	else:
		result = iN
	o.write('Case #{}: {}{}'.format(t+1, result, ['\n', ''][t==T-1]))

i.close()
o.close()