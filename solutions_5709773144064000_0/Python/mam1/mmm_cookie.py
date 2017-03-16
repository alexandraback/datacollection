#MMM, Google Code Jam Problem 2, Cookie

infile = open("B-small-attempt0.in", "r")
outfile = open("output.txt", "w")

numtests = int(infile.readline())

for T in range(numtests):

	(C, F, X) = map(float, infile.readline().split(' '))
	speed = 2.0
	time = 0.0

	while(True):
		rushTime = X/speed
		buildTime = C/speed + X/(speed+F)

		if rushTime < buildTime:
			break
		else:
			time += C/speed
			speed += F

	time += X/speed

	outfile.write("Case #"+str(T+1)+": ")
	print >>outfile, "%.7f" % time