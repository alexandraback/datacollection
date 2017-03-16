import itertools


						
	
f = open('a.txt', 'r')
f0 = open('output.txt', 'w')
a0 = [int(x) for x in f.readline().split()]
cont = 0;
for index in range (0,a0[0]):
	print(index)
	cont = 0;
	f0.write('Case #')
	f0.write(str(index+1))
	f0.write(': ')
	n, = [int(x) for x in f.readline().split()];
	a = ['']*n;
	a = f.readline().split();
	b = [0]*26;
	for i in range(0,n):
		c = a[i][0]
		d = a[i][0]
		for j in range (1, len(a[i])):
			if (not (a[i][j] == d)):
				c = c+a[i][j]
				d = a[i][j];
		for j in range (0,len(c)):
			if (b[ord(c[j])-97]):
				f0.write('0'+'\n');
				cont = 1;
				break;
			if ((j > 0) & (j < len(c)-1)):
				b[ord(c[j])-97] = 1;
		if(cont):
			break;
		e = a[i][0];
		e = e+ c[len(c)-1];
		a[i] = e;
	if(cont):
		continue;
	z = [1]*n;
	for i in range (0,n):
		z[i] = i;
	y = list(itertools.permutations(z));
	count = 0;
	plcont = 1;
	
	for i in range(0,len(y)):
		plcont = 1;
		e = '';
		for j in range (0, n):
			e = e+a[y[i][j]];
		g = e[0];
		p = [0]*26;
		p[ord(g)-97] = 1;
		for j in range (1,len(e)):
			if (not(e[j] == g)):
				if (p[ord(e[j])-97]):
					plcont = 0;
					break;
				p[ord(e[j])-97] = 1;
				g = e[j];
		if (plcont): 
			count = count + 1;
	
	
					
		
	
	f0.write(str(count)+'\n')		
			
		
			

