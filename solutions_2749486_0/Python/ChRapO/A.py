import sys

cases = sys.stdin.readline()

for case in range(0,int(cases)):	
	print "Case #%d: " % (case+1),
	X,Y = [int(v) for v in sys.stdin.readline().split()]

	x = 0
	i = 1
	while x!=X:
		if i%2: 
			x += i
			sys.stdout.write('E')
		else: 
			x -= i
			sys.stdout.write('W')
		i+=1

	y = 0
	d = 1
	if Y>0:
		if Y<i: d = (i+1)%2
		else: d = i%2
	else:
		if abs(Y)<i: d = i%2
		else: d = (i+1)%2

	while y!=Y:
		if i%2 == d: 
			y += i
			sys.stdout.write('N')
		else: 
			y -= i
			sys.stdout.write('S')
		i+=1

	sys.stdout.write('\n')
