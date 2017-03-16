import sys

f = open(sys.argv[1], 'r')
result = open(sys.argv[1]+'.sol','w')
T=eval(f.readline())
print 'T = ', T
for t in range(T):
	N=eval(f.readline())
	print 'N = ', N
	if N == 0:
		result.write('Case #'+str(t+1)+': INSOMNIA\r')
	else:
		s = set()
		curr = N
		while 1:
			for digit in str(curr):
				s.add(digit)
			sleep = True
			for i in range(10):
				if str(i) not in s:
					sleep = False
			if sleep:
				break
			else:
				curr += N
		print 'Case #'+str(t+1)+': '+str(curr)
		result.write('Case #'+str(t+1)+': '+str(curr)+'\n')

f.close()
result.close()