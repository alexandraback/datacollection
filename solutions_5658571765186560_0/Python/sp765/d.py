def solve(X, R, C):
	if R*C % X != 0:
		return "RICHARD"

	if X == 3:
		if R==1 or C==1:
			return "RICHARD"
		return "GABRIEL"
	if X == 4:
		if R <= 2 or C <= 2:
			return "RICHARD"
		if R <= 3 and C <= 3:
			return "RICHARD"
		return "GABRIEL"

	return "GABRIEL"


fin = open("D-small-attempt0.in", "r") 
lines = fin.readlines()

index = 0
T = int(lines[index])
index += 1

for i in range(0, T):
	X, R, C = [int(s) for s in lines[index].split()]
	index += 1
	print "Case #" + str(i+1) + ": " + solve(X, R, C)
