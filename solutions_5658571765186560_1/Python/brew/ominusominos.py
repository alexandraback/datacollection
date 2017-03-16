import math

def solve(X,R,C):
	if X > 6: 
		return "RICHARD"
	if X == 1:
		return "GABRIEL"
	if R < X and C < X:
		return "RICHARD"
	if R < math.ceil(float(X)/2) or C < math.ceil(float(X)/2):
		return "RICHARD"
	if R == math.ceil(float(X)/2) or C == math.ceil(float(X)/2):
		if X == 4 or X == 6:
			return "RICHARD"
	if (R*C - X)%X != 0:
		return "RICHARD"
	return "GABRIEL"


g = open("D-large-out.txt","w")


f = open("D-large.in","r")
d = f.read().split("\n")
n = int(d[0])

j = 1
for i in range(1,n+1):
	X = int(d[i].split(" ")[0])
	R = int(d[i].split(" ")[1])
	C = int(d[i].split(" ")[2])
	g.write ("Case #" + str(i) + ": " + solve(X,R,C) + "\n")