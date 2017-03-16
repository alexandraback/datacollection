def f(b,m):
	if m > 2**(b-2):
		return "IMPOSSIBLE"
	ans = "POSSIBLE\n"
	grid = []
	for i in range(b):
		grid.append([0] * b)
	for i in range(b-1):
		for j in range(b-1):
			if j > i:
				grid[i][j] = 1
	if m == 2**(b-2):
		for i in range(b-1):
			grid[i][b-1] = 1
		return ans + printGrid(grid)
	binary = ''.join(reversed(bin(m)))
	for i in range(b-2):
		if binary[i] == 'b':
			break
		if binary[i] == '1':
			grid[i+1][b-1] = 1
	return ans + printGrid(grid)




def printGrid(g):
	x = list(map(lambda x: ''.join(map(str,x)),g))
	return '\n'.join(x)


n = int(input())
for i in range(n):
	x = f(*map(int,input().split()))
	print("Case #{0}: {1}".format(i+1, x))