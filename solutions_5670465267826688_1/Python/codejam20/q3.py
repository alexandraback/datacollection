import sys

def mult(x,y):
	if x[0] == '-':
		return negative(mult(x[1],y))
	if y[0] == '-':
		return negative(mult(x,y[1]))
	if x == 'o':
		return y
	if y == 'o':
		return x
	if x == 'i':
		if y == 'i':
			return '-o'
		if y == 'j':
			return 'k'
		if y == 'k':
			return '-j'
	if x == 'j':
		if y == 'i':
			return '-k'
		if y == 'j':
			return '-o'
		if y == 'k':
			return 'i'
	if x == 'k':
		if y == 'i':
			return 'j'
		if y == 'j':
			return '-i'
		if y == 'k':
			return '-o'

def negative(x):
	if x[0] == '-':
		return x[1]
	else:
		return '-' + x

def solve(s, repeat):
	reducedRepeat = repeat % 4
	product = 'o'
	foundI = False
	foundNextJ = False
	for c in s:
		product = mult(product, c)
		if product == 'i':
			foundI = True
		if foundI and product == 'k':
			foundNextJ = True
	final = 'o'
	for i in range(reducedRepeat):
		final = mult(final,product)
	
	#print s, repeat, 'final', final			

	if final != '-o':
		return 'NO'
	else:
		if foundNextJ:	
			return 'YES'
		else:
			if foundI:
				for i in range(min(3,repeat)):
					for c in s:
						product = mult(product,c)
						if product == 'k':
							return 'YES' 
				return 'NO'
			else:
				for i in range(min(7,repeat)):
					for c in s:
						product = mult(product,c)
						if product == 'i':
							foundI = True
						if foundI and product == 'k':
							return 'YES'
				return 'NO'	

#inFile =  open(str(sys.argv[1]), 'r')
fileName = 'C-large'
#fileName = 'B-small-attempt0'
inFile = open(fileName + '.in', 'r')
outFile = open(fileName + '.out', 'w')

inFile.readline()
nextLine = inFile.readline()
i = 0
while (nextLine != ""):
	i = i + 1
	print i
	repeat = int(nextLine[:-1].split(' ')[1])
	s = inFile.readline()[:-1]
	#for j in range(repeat):
	#	s = s + nextLine
	nextLine = inFile.readline()
	r = solve(s,repeat)
	outFile.write('Case #{}: {}\n'.format(i,r))

inFile.close()
outFile.close()	

