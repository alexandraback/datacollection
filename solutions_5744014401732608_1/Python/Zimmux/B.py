import fileinput
stdin = fileinput.input()

def solveCase():
	B,M = map(int,next(stdin).split())
	sl = [[1]*y+[0]*(B-y) for y in range(B)] # 1s below diagonal
	W = [0]*B
	W[0] = 1
	for y in range(1,B):
		W[y] = sum(W[x]*sl[y][x] for x in range(y))
	m = W[B-1]-M # excess
	if m<0:
		return "IMPOSSIBLE"
	for x in range(B-1)[::-1]:
		if m>W[x]:
			m -= W[x]
			sl[x][B-1] = 0

	return "POSSIBLE\n"+"\n".join("".join(str(sl[y][x]) for x in range(B)) for y in range(B))

for case in range(int(next(stdin))):
	print("Case #{0}: {1}".format(case+1,solveCase()))