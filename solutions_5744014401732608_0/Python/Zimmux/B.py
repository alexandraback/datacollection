import fileinput
stdin = fileinput.input()

def dags(N):
	for g in range(2**(N*(N-1)//2)):
		m = [[0]*N for j in range(N)]
		i = 0
		for y in range(N):
			for x in range(N):
				if x>y:
					m[y][x] = (g>>i)&1
					i += 1
		yield m

def solveCase():
	B,M = map(int,next(stdin).split())
	for sl in dags(B):
		W = [0]*B
		W[0] = 1
		for y in range(1,B):
			W[y] = sum(W[x]*sl[x][y] for x in range(y))
		if W[B-1]==M:
			return "POSSIBLE\n"+"\n".join("".join(str(sl[y][x]) for x in range(B)) for y in range(B))
	return "IMPOSSIBLE"

for case in range(int(next(stdin))):
	print("Case #{0}: {1}".format(case+1,solveCase()))