f = open('D-large.in', 'r')
f0 = open('output.txt', 'w')
a0 = [int(x) for x in f.readline().split()];
for j in range (0, a0[0]):
	a1 = [int(x) for x in f.readline().split()];
	print(a1[0])
	a = [float(x) for x in f.readline().split()];
	b = [float(x) for x in f.readline().split()];
	a.sort();
	b.sort();
	c1 = a1[0];
	c = a;
	d = b;
	print(c1)
	if (d[c1-1] == 1.0):
		d.pop(c1-1)
		c.pop(1)
		c1 = c1-1
	y = 0
	o1 = 0;
	for k in range (0, c1):
		if (c[k] > d[y]):
			o1 = o1+1
			y = y+1
	y = 0
	o2 = 0
	for k in range (0, a1[0]):
		if (c[y] < d[k]):
			o2 = o2+1
			y = y+1
	o2 = a1[0]-o2
	f0.write('Case #')
	f0.write(str(j+1))
	f0.write(': ')
	f0.write(str(o1))
	f0.write(' ')
	f0.write(str(o2))
	f0.write('\n')
			
		
		
		
