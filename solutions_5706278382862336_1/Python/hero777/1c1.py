from fractions import gcd
f = open('a.txt', 'r')
f0 = open('output.txt', 'w')
a0 = [int(x) for x in f.readline().split()]
for index in range (0,a0[0]):
	x,y = [int(x) for x in f.readline().split('/')];
	print(x)
	print(y)
	z = int(gcd(x,y));
	#print(x/z)
	x = int(x/z);
	#print(y/z)
	y = int(y/z);
	f0.write('Case #')
	f0.write(str(index+1))
	f0.write(': ')
	if (x >y):
		f0.write('impossible'+ '\n');
		continue;
	if (x==y):
		f0.write('0' + '\n');
		continue;
	a = bin(x)[2:];
	print(a)
	b = bin(y)[2:];
	print(b)
	if (len(b) == 1):
		f0.write('0'+'\n');
		continue;
	c = int(b[1:],2);
	if (not c == 0):
		f0.write('impossible'+ '\n');
		continue;
	f0.write(str(len(b)-len(a))+'\n');
 
		
		
	
	
	
