f = open('a.txt', 'r')
f0 = open('output.txt', 'w')
a0 = [int(x) for x in f.readline().split()]
for index in range (0,a0[0]):
	x, y,z = [int(x) for x in f.readline().split()]
	f0.write('Case #')
	f0.write(str(index+1))
	f0.write(': ')
	ans = 0
	for i in range (0,x):
		for j in range (0,y):
			if (i&j < z):
				ans = ans+1;
	f0.write(str(ans)+'\n');
		
