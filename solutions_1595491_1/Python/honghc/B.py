def p(i):
	k = i.split(' ')
	o = []
	o.append(int(k[0]))
	o.append(int(k[1]))
	o.append(int(k[2]))
	t = k[3:]
	for i in range(len(t)):
		t[i] = int(t[i])
	o.append(sorted(t, reverse=True))
	return o

def q(l):
	l = p(l)
	o = 0
	for i in range(l[0]):
		if int(l[3][i]) >= l[2]*3-2:
			o = o + 1
		elif l[1]>0 and l[2]>1 and int(l[3][i]) >= l[2]*3-4:
			o = o + 1
			l[1] = l[1] - 1
		else:
			break
	return o

input = open('./sample.txt', 'r')
output = open('./output.txt', 'w')
case = int(input.readline())

for i in range(case):
	o = q(input.readline())

	output.write('Case #{0}: {1}\n'.format(i+1, o))
	print 'Case #{0}: {1}'.format(i+1, o)