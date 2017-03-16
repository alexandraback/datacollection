import math
def solve(R,C,W):
	if C % W > 0:
		return (C/W)*R + W
	else:
		return (C/W)*R + W - 1

def dosolve(f,g):
	d = f.read().split("\n")
	n = int(d[0])

	j = 1
	for i in range(1,n+1):
		data = d[i].split(" ")
		R = int(data[0])
		C = int(data[1])
		W = int(data[2])
		print solve(R,C,W)
		g.write ("Case #" + str(i) + ": " + str(solve(R,C,W)) + "\n")

	return 0

def solve_large():
	g = open("A-large-final.txt","w")
	f = open("A-large.in","r")
	dosolve(f,g)

def solve_small():
	g = open("A-small-out1.txt","w")
	f = open("A-small-attempt1.in","r")
	dosolve(f,g)

def solve_examples():
	g = open("A-eg-out.txt","w")
	f = open("A-eg.in","r")
	dosolve(f,g)
	
# solve_examples()
# solve_small()
solve_large()