import sys

f_i = open(sys.argv[1], 'r')
f_o = open(sys.argv[2], 'w')

count = int(f_i.readline())

for x in range(count):
	line = f_i.readline().replace('\n','').split(' ')
	A = int(line[0])
	B = int(line[1])
	y = 0
	length = len(str(A))
	if length == 1:
		pass
	else:
		for n in range(A,B):
			used = []
			for i in range(1, length):
				sTest = str(n)[i:]+str(n)[:i]
				m = int(sTest)
				if A<=n and n<m and m<=B and n!=m:
					if m not in used:
						y = y + 1
						used.append(m)
	f_o.write('Case #%d: %d\n'%(x+1,y))