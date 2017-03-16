f = open('a.txt','r')
f0 = open('output.txt','w')
a0 = [int(x) for x in f.readline().split()]
print(a0[0])
for index in range (0,a0[0]):
	print(index)
	x,y = f.readline().split()
	x = int(x)
	f0.write('Case #')
	f0.write(str(index+1))
	f0.write(': ')
	if x == 0:
		f0.write('0')
		f0.write('\n')
		continue
	z = [int(i) for i in y]
	m = 0
	count = z[0]
	for index2 in range (1,x+1):
		m = max(m, index2 - count)
		count = count + z[index2]
		
	if m > 0:
		f0.write(str(m))
	else:
		f0.write('0')
	f0.write('\n')
		



