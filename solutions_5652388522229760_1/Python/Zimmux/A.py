import fileinput
stdin = fileinput.input()

def solveCase():
	N = int(next(stdin))
	if N==0:
		return "INSOMNIA"
	todo = set(range(10))
	i = 0
	while todo:
		i += 1
		k = i*N
		while k:
			r,k = k%10,k//10
			if r in todo:
				todo.remove(r)
	return i*N

for case in range(int(next(stdin))):
	print("Case #{0}: {1}".format(case+1,solveCase()))