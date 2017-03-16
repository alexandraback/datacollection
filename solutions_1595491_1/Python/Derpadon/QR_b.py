import sys

f_i = open(sys.argv[1], 'r')
f_o = open(sys.argv[2], 'w')

count = int(f_i.readline())

for x in range(count):
	line = f_i.readline().replace('\n','').split(' ')
	N = int(line[0])
	S = int(line[1])
	p = int(line[2])
	t = []
	y = 0
	for j in range(3,len(line)):
		t.append(int(line[j]))
	t.sort()
	for j in range(len(t)):
		if t[j] < p:
			pass
		elif t[j] >= (3*p-2):
			y = y + 1
		elif t[j] >= (3*p-4) and S>0:
			y = y + 1
			S = S - 1
	f_o.write('Case #%d: %d\n'%(x+1,y))