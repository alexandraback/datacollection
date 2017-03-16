import re

with open('C-small-attempt0.in') as f:
	input = f.readlines()

T = int(input[0])
output = ''

for index in range(T):
	output += 'Case #' + str(index+1) + ':\n'
	row = re.findall(r'\d+', input[index+1])
	R = int(row[0])
	C = int(row[1])
	M = int(row[2])
	grid = []
	for i in range(R):
		grid.append('*' * C)
	n_empty = R*C-M
	c_empty = 1
	state = 0
	grid[0] = '.' + grid[0][1:]
	while c_empty < n_empty:
		n_min = 9
		i_min = 0
		j_min = 0
		for i in range(R):
			for j in range(C):
				n_around = 0
				if grid[i][j] == '.':
					if j+1 < C and grid[i][j+1] == '*':
						n_around += 1
					if i+1 < R and j+1 < C and grid[i+1][j+1] == '*':
						n_around += 1
					if i+1 < R and grid[i+1][j] == '*':
						n_around += 1
					if i+1 < R and j-1 >= 0 and grid[i+1][j-1] == '*':
						n_around += 1
					if i-1 >= 0 and j+1 < C and grid[i-1][j+1] == '*':
						n_around += 1
					if c_empty + n_around == n_empty:
						c_empty += n_around
						state = 1
						if j+1 < C:
							grid[i] = grid[i][:j+1] + '.' + grid[i][j+2:]
						if i+1 < R and j+1 < C:
							grid[i+1] = grid[i+1][:j+1] + '.' + grid[i+1][j+2:]
						if i+1 < R:
							grid[i+1] = grid[i+1][:j] + '.' + grid[i+1][j+1:]
						if i+1 < R and j-1 >= 0:
							grid[i+1] = grid[i+1][:j-1] + '.' + grid[i+1][j:]
						if i-1 >= 0 and j+1 < C:
							grid[i-1] = grid[i-1][:j+1] + '.' + grid[i-1][j+2:]
						break
					if n_around != 0 and n_around < n_min:
						n_min = n_around
						i_min = i
						j_min = j
			if state == 1:
				break
		if state == 1:
			break
		if j_min+1 < C:
			grid[i_min] = grid[i_min][:j_min+1] + '.' + grid[i_min][j_min+2:]
		if i_min+1 < R and j_min+1 < C:
			grid[i_min+1] = grid[i_min+1][:j_min+1] + '.' + grid[i_min+1][j_min+2:]
		if i_min+1 < R:
			grid[i_min+1] = grid[i_min+1][:j_min] + '.' + grid[i_min+1][j_min+1:]
		if i_min+1 < R and j_min-1 >= 0:
			grid[i_min+1] = grid[i_min+1][:j_min-1] + '.' + grid[i_min+1][j_min:]
		if i_min-1 >= 0 and j_min+1 < C:
			grid[i_min-1] = grid[i_min-1][:j_min+1] + '.' + grid[i_min-1][j_min+2:]
		c_empty += n_min
	grid[0] = 'c' + grid[0][1:]
	if c_empty == n_empty:
		for i in range(R):
			output += grid[i]
			output += '\n'
	else:
		output += 'Impossible\n'

with open('C-small-attempt0.out', 'w') as f:
	f.write(output)