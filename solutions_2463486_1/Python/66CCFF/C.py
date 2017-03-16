def check(x):
	a = str(x)
	l = len(a)
	pos = (l + 1)>>1
	for i in range(0, pos):
		if a[i] != a[l-i-1]:
			return False
	return True

p = []

for i in range(1, 10000000):
	if not check(i):
		continue
	x = i * i
	if check(x):
		p.append(x)

f = open('in.in', 'r')
line = f.readline()
n = int(line)
size = len(p)

f2 = open('data.txt', 'w')
for it in p:
	f2.write(str(it)+'\n')
f2.close()

def fmin(x):
	for i in range(0, size):
		if p[i] >= x:
			return i+1
	return size

def fmax(x):
	for i in range(size-1, -1, -1):
		#print 'i =', i, p[i]
		if p[i] <= x:
			return i+1
	return 1

f1 = open('out.txt', 'w')

for i in range(0, n):
	line = f.readline()
	if not line:
		break
	a, b = line.split()
	a = int(a)
	b = int(b)
	f1.write( 'Case #' + str(i+1) + ': ' + str(fmax(b) - fmin(a) + 1) + '\n')

f.close()
f1.close()
