import sys

file="A"
file = sys.argv[1]

lines = open(file).readlines()
N = int(lines[0])

currentLine = 1

for case in range(N):
	number = int(lines[currentLine])
	currentLine = currentLine + 1
	Nblocks = map(float,lines[currentLine].split())
	currentLine = currentLine + 1
	Kblocks = map(float,lines[currentLine].split())
	currentLine = currentLine + 1
	Nblocks = sorted(Nblocks)
	Kblocks = sorted(Kblocks)
	
	#ken strategy, play next highest block always
	#naomi, play top to bottom
	
	warcount = 0
	N = Nblocks[:]
	K = Kblocks[:]
	while len(N):
		if N[-1] > K[-1]:
			warcount +=1
			N = N[:-1]
			K = K[1:]
		else:
			N = N[:-1]
			K = K[:-1]
	
	#Naomi Lie.   Play lowest block and lie that it is between top two.
	liewarcount = 0
	N = Nblocks[:]
	K = Kblocks[:]
	while len(N):
		if N[-1] > K[-1]:
			liewarcount +=1
			N = N[:-1]
			K = K[:-1]
		else:
			N = N[1:]
			K = K[:-1]

	print "Case #{}: {} {}".format(case + 1 ,liewarcount, warcount )
	
