fileIn = open ("C:/Testes/Google/Round1B/b/B-small-attempt0.in","r");
fileOut = open ("C:/Testes/Google/Round1B/b/B-small-attempt0.out","w");

lines = []
for line in fileIn:
	lines.append(line)

numCases = int(lines[0])
lines.pop(0)

i = 0
for n in range(0, numCases):
	numbers = lines[i].split()
	i+=1
	a = int(numbers[0])
	b = int(numbers[1])
	k = int(numbers[2])
	m = 0
	for j in range(0, a):
		for l in range(0, b):
			if j&l < k:
				m+=1
	
	fileOut.write('Case #'+str(n+1)+': '+str(m)+'\n')

fileIn.close()
fileOut.close()
