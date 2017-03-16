def betterof(c1,c2):
	if c1 == None:
		return c2
	if c2 == None:
		return c1
	if abs(c1[0] - c1[1]) < abs(c2[0] - c2[1]):
		return c1
	if abs(c1[0] - c1[1]) > abs(c2[0] - c2[1]):
		return c2
	if(c1[0] < c2[0]):
		return c1
	if(c1[0] > c2[0]):
		return c2
	if(c1[1] < c2[1]):
		return c1
	return c2

def matchor0(a,b):
	if a == '?':
		if b == '?':
			return '0'
		else:
			return b
	else:
		return a

def firstbigger(c,j,differ):
	s = ""
	for i in range(differ):
		s += matchor0(c[i],j[i])
	return (int(s + c[differ:].replace("?", "0")), int(s + j[differ:].replace("?", "9")))

def secondbigger(c,j,differ,kk=999):
	cout = ""
	jout = ""
	madediff = False
	made90diff = -1
	for i in range(differ-1, -1, -1):
		if madediff:
			cout = matchor0(c[i],j[i]) + cout
			jout = matchor0(c[i],j[i]) + jout
			continue
		if c[i] == '9' or j[i] == '0':
			cout = '9' + cout
			jout = '0' + jout
		elif c[i] == '?' and j[i] == '?':
			if kk > i:
				made90diff = i
				cout = '9' + cout
				jout = '0' + jout
			else:
				cout = '0' + cout
				jout = '1' + jout
				madediff = True
		elif c[i] == '?':
			cout = str(int(j[i])-1) + cout
			jout = j[i] + jout
			madediff = True
		else:
			cout = c[i] + cout
			jout = str(int(c[i])+1) + jout
			madediff = True
	
	if madediff:
		c1 =( int(cout + c[differ:].replace("?", "9")), int(jout + j[differ:].replace("?", "0")))
	else:
		c1 = None
	
	c2 = None
	
	if made90diff > -1:
		c2 = secondbigger(c,j,differ,made90diff)
		
	return betterof(c1,c2)
		
	
	

def solve(c,j):
	cc = ""
	jj = ""
	differ = -1
	diff = 0
	for i in range(len(c)):
		if c[i] != j[i] and c[i] != '?' and j[i] != '?':
			differ = i
			diff = int(c[i]) -int(j[i])
			break
	
	
	if differ == -1:
		s = ""
		for i in range(len(c)):
			s += matchor0(c[i],j[i])
		return (int(s),int(s))
	
	if diff > 0:
		c1 = firstbigger(c,j,differ)
		c2 = secondbigger(c,j,differ)
	else:
		jbigger = firstbigger(j,c,differ)
		jsmaller = secondbigger(j,c,differ)
		c1 = (jbigger[1],jbigger[0])
		c2 = None
		if jsmaller != None:
			c2 =(jsmaller[1],jsmaller[0])
	
	return betterof(c1,c2)

f = open('B-large.in','r')
out = open('out.txt', 'w')

cases = int(f.readline())
for case in range(1,cases+1):
	c,j = [x for x in f.readline().split()]
	output = 'Case #{0}: '.format(case) + ' '.join([str(x).zfill(len(c)) for x in solve(c,j)]) + "\n"
	print(output)
	out.write(output)

out.close()