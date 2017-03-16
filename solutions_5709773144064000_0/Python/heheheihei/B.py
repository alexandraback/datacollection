#! /usr/bin/python

if __name__ == "__main__":
	outputFile = open("B.out", "w") 
	data = [[float(numStr) for numStr in line.split()] for line in open("B.in", "r")]
	numOfCase = int(data[0][0])
	for caseIndex in range(numOfCase):
		C = data[caseIndex + 1][0]
		F = data[caseIndex + 1][1]
		X = data[caseIndex + 1][2]
		G = 2.0
		time = 0.0
		while True:
			if (X - C) < (X * G / (F + G)):
				time += X / G
				break
			else:
				time += C / G
				G += F
		outputLine = "Case #%d: %.7f\n" % (caseIndex + 1, time)
		outputFile.write(outputLine)
		#print outputLine
	outputFile.close()
