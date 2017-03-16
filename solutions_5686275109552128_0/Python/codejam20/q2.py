import sys

def solve(l):
	pMax = 9
	if max(l) <= 3:
		return max(l)
	l.sort()
	for i in range(0, pMax + 1):
		if feasible(l,i):
			return i

def feasible(l,i):
	if max(l) <= i:
		return True
	if i < 0:
		return False
	if max(l) <=3:
		return max(l) <= i
	
	m = l[:]
		
	m = m + [(1+max(m))/2, max(m)/2]
	m.remove(max(m))
	if (feasible(m, i-1)):
		return True;
	
	m = l[:]			
	m = m + [(2+max(m))/3, (1+max(m))/3, max(m)/3]
	m.remove(max(m))
	if (feasible(m, i-2)):
		return True;

	return False;

def solve_old(l):
	if len(l) == 0:
		return 0
	if max(l) <= 3:
		return max(l)
	else:
		maximum = max(l)
		i = 0
		while i in range(len(l)):
			x = l[i]
			if x > 3:
				c =  solve_old(l[:i] + [x/2, (x+1)/2] + l[i+1:]) + 1
				if c < maximum:
					maximum = c
			if x == 0:
				l = l[:i] + l[i+1:]
			else:
				i = i + 1
	return maximum
		

#inFile =  open(str(sys.argv[1]), 'r')

fileName = 'B-small-attempt5'
#fileName = 'qual1dummy'
inFile = open(fileName + '.in', 'r')
outFile = open(fileName + '.out', 'w')

inFile.readline()
nextLine = inFile.readline()
i = 0
while (nextLine != ""):
	i = i + 1
	print i
	l = [int(x) for x in inFile.readline()[:-1].split(' ')]
	nextLine = inFile.readline()
	s = solve(l)
	outFile.write('Case #{}: {}\n'.format(i,s))

inFile.close()
outFile.close()	

