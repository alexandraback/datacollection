import sys

file="A"
file = sys.argv[1]

lines = open(file).readlines()
N = int(lines[0])

currentLine = 1

rate = 2.0

for case in range(N):
	C,F,X = map(float, lines[currentLine].split())
	currentLine = currentLine + 1
	solutions = []
	
	for i in range(0,10000):
		if len(solutions) ==0:
			solutions.append([0, rate, X/rate])
			continue
		#next factory time , needed / Previous rate plus previous total time to create factories
		timeToNext = C / solutions[-1][1] + solutions[-1][0]

		toprate = i * F + rate
		timeToFinish = X / toprate + timeToNext
		
		solutions.append([timeToNext, toprate, timeToFinish])
		#print [timeToNext, toprate, timeToFinish]
		if len(solutions) > 1:
			if solutions[-1][2] > solutions[-2][2]:
				break;
	
	print "Case #{}: {:.7f}".format(case + 1 ,solutions[-2][2])

