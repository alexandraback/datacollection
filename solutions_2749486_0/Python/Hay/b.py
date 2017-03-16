import sys

t = int(sys.stdin.readline())

f = open('b.out','w')

for i in range(t):
	a, b = [int(x) for x in sys.stdin.readline().split()]
	if a > 0:
		x = ['W', 'E']
	elif a < 0:
		x = ['E', 'W']
	else :
		x = None
	if b > 0:
		y = ['S', 'N']
	elif b < 0:
		y = ['N', 'S']
	else:
		y = None
	print 'Case #%d:'%(i+1),
	f.write('Case #%d: '%(i+1))
	if x != None:
		for i in range(abs(a)):
			print x[0], x[1],
			f.write('%s%s'%(x[0],x[1]))
	if y != None:
		for i in range(abs(b)):
			print y[0], y[1],
			f.write('%s%s'%(y[0],y[1]))
	print 
	f.write('\n')
	
f.close()