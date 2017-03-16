import sys, math

def solve(x, y):
	path = ""
	if (x >= 0):
		path += "WE"*x
	else:
		path += "EW"*(-x)
	
	if (y >= 0):
		path += "SN"*y
	else:
		path += "NS"*(-y)
	return path

infile = open(sys.argv[1],'r')
n = int(infile.readline().strip())
for i in range(n):
	args = infile.readline().strip().split()
	#integer needs to be represented as a list of digits
	x = int(args[0])
	y = int(args[1])
	print("Case #" + str(i+1) + ": " + str(solve(x, y)))

