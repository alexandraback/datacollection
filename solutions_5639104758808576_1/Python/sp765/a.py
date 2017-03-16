import math

def solve(Smax, count):
	total = 0
	needed = 0
	for i in range(0, Smax+1):
		if total < i:
			needed += i-total
			total += i-total
		total += int(count[i])
	return needed

fin = open("A-large.in", "r") 
lines = fin.readlines()

index = 0
T = int(lines[index])
index += 1

for i in range(0, T):
	Smax, count = [s for s in lines[index].split()]
	Smax = int(Smax)
	index += 1
	print "Case #" + str(i+1) + ": " + str(solve(Smax, count))
