import fileinput
stdin = fileinput.input()

def solveCase():
	P = next(stdin)[:-1]+'+'
	return sum(1 for p,q in zip(P,P[1:]) if p!=q)

for case in range(int(next(stdin))):
	print("Case #{0}: {1}".format(case+1,solveCase()))