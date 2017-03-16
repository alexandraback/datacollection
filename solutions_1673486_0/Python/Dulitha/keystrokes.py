

def backspaceX(a, b, x, probabilities):
	totalEX = 0.0
	tempEX = 1.0
	for i in range(a - x):
		tempEX = probabilities[i] * tempEX
	return tempEX * (1.0 + (b - a) + 2*x) + ((1.0 - tempEX) * (2 + (b - a) + 2*x + b))
	
	 

def calculate(line1, line2):
	aS,bS = line1.split()
	a = int(aS)
	b = int(bS)
	probabilitiesS = line2.split()
	probabilities = []
	for p in probabilitiesS:
		probabilities.append(float(p))
		
	min = 2 + b
	for x in range(a):
		eX = backspaceX(a,b,x,probabilities)
		if eX < min:
			min = eX
	return min


if __name__ == "__main__":
	import sys
	file = open(sys.argv[1],'r')
	numTests = file.readline()
	for case in range(int(numTests)):
		line1 = file.readline()
		line2 = file.readline()
		string = "Case #"+str(case+1)+": "+str(calculate(line1, line2))
		string = string.rstrip()
		string = string.lstrip()
		print string
		