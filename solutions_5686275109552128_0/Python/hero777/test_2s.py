import math
f = open('a.txt','r')
f0 = open('output2.txt','w')
a0 = [int(x) for x in f.readline().split()]
for index in range (0,a0[0]):
	print(str(index)+'yahoo')
	x = [int(x) for x in f.readline().split()]
	y = [int(y) for y in f.readline().split()]
	y1 = list(y)
	z = int(math.ceil(math.sqrt(float(sum(y)))))
	count = 0
	m = max(y)
	m1 = m
	for index3 in range (2,m):
		count = 0
		for index2 in range (0,x[0]):
			count = count+ math.ceil(float(y[index2])/float(index3))-1
		print(count)
		print(count+index3)
		m1 = min(m1, count+index3)
	f0.write('Case #')
	f0.write(str(index+1))
	f0.write(': ')
	f0.write(str(m1))
	f0.write('\n')
