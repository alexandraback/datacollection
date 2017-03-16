import math

def solve(ps):
	minT = 1001
	for p_max in range(1, 1001):
		time = p_max
		for p in ps:
			if p > p_max:
				time += int(math.ceil(float(p) / p_max) - 1)
		minT = min(minT, time)
	return minT

fin = open("B-small-attempt0.in", "r") 
lines = fin.readlines()

index = 0
T = int(lines[index])
index += 1

for i in range(0, T):
	D = int(lines[index])
	ps = [int(s) for s in lines[index+1].split()]
	index += 2

	print "Case #" + str(i+1) + ": " + str(solve(ps))
