import sys
from decimal import *

filename = sys.argv[1]
f = open(filename, 'r')

numCases = int(f.readline())

for t in range(numCases):
	line = f.readline().strip().split(' ')
	C = Decimal(line[0])
	F = Decimal(line[1])
	X = Decimal(line[2])
	R = Decimal('2.0')

	past = Decimal('0.0')
	time = X/R
	timeToFarm = C/R
	timeWithFarm = timeToFarm + X/(R+F)
	
	while time > timeWithFarm:
		past = past + timeToFarm
		R = R+F
		time = X/R
		timeToFarm = C/R
		timeWithFarm = timeToFarm + X/(R+F)
	
	print 'Case #'+str(t+1)+': '+str(time+past)




