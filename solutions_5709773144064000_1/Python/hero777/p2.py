f = open('B-large.in', 'r')
f0 = open('output.txt', 'w')
a0 = [int(x) for x in f.readline().split()];
for j in range(0, a0[0]):
	a = [float(x) for x in f.readline().split()];
	print(a)
	b = a[2]/a[0] - 2/a[1]
	print (int(b))
	c = 0.0
	if b < 1:
		c = a[2]/2;
	else:
		for i in range(0,int(b)):
			c = c+a[0]/(2.0 + (i)*a[1])
			
		c = c+a[2]/(2.0 + (int(b))*a[1])
	print ('%.7f' %c)
	f0.write('Case #')
	f0.write(str(j+1))
	f0.write(': ')
	f0.write(str('%.7f' %c))
	f0.write('\n')	
f0.close
f.close
	

