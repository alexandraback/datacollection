import sys

def solve(smax, l):
	total = 0
	required = 0
	for i in range(smax + 1):
		print total, i
		if total < i:
			required = required + 1
			total = total + 1
		total = total + l[i]
	return required	
		
#inFile =  open(str(sys.argv[1]), 'r')
fileName = 'A-small-attempt1'
inFile = open(fileName + '.in', 'r')
outFile = open(fileName + '.out', 'w')

inFile.readline()
nextLine = inFile.readline()
i = 0
while (nextLine != ""):
	i = i + 1
	line = nextLine.split(' ')
	smax = int(line[0])
	l = []
	for j in range(len(line[1]) - 1):
		l.append(int(line[1][j]))
	nextLine = inFile.readline()
	s = solve(smax,l)
	outFile.write('Case #{}: {}\n'.format(i,s))

inFile.close()
outFile.close()	

