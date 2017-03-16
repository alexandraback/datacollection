def output(pattern, numbers):
	s = []
	k = 0
	while(pattern>0):
		if(pattern%2==1):
			s.append(str(numbers[k]))
		k = k+1
		pattern = pattern/2
	print ' '.join(s)



def solveone(N,indata):
	dic = {}
	for i in range(2**N):
		j = i
		k = 0
		subsum = 0
		while j>0:
			if (j%2==1):
				subsum = subsum + indata[k]
			j = j/2
			k = k+1
		if(dic.has_key(subsum)):
			output(dic[subsum],indata)
			output(i,indata)
			return True
		dic[subsum] = i
	print 'Impossible'
	return False


inputfile = 'small.in'
# inputfile = 'test.in'
lines = file(inputfile,'r').readlines()
T = int(lines[0])
for t in range(T):
	line = lines[t+1].split(' ')
	N = int(line[0])
	indata = []
	for i in range(N):
		indata.append(int(line[i+1]))
	print 'Case #'+str(t+1)+':'
	solveone(N,indata)





