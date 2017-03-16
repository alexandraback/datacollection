import sys

input = open(sys.argv[1], 'r')
t = int(input.readline()[:-1])
for x in range(1, t+1):
	line = input.readline()[:-1].split()
	C = float(line[0])
	F = float(line[1])
	X = float(line[2])
	cookies = 0
	rate = 2
	time = 0
	if (C > X):
		time = X/rate
		cookies = X
	else:
		while(cookies<X):
			if (cookies < C):
				time += (C-cookies)/rate
				cookies = C
			waitTime = (X - cookies)/rate
			buyTime = X/(rate + F)
			if (buyTime < waitTime):
				cookies = 0
				rate += F
			else:
				time+=waitTime
				cookies = X
	print "Case #" + str(x) + ": " + str(time)
