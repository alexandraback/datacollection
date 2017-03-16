def is_filled(grid):
	filled = True
	for i in range(4):
		if grid[i].find('.') != -1:
			filled = False
			break
	return filled

def is_win_for(p, grid):
	#search in lines
	for i in range(4):
		x = grid[i]
		if (x[0] == p or x[0] == 'T') and (x[1] == p or x[1] == 'T') and (x[2] == p or x[2] == 'T') and (x[3] == p or x[3] == 'T') :
			return True
	
	#search in columns
	for i in range(4):
		if (grid[0][i] == p or grid[0][i] == 'T') and (grid[1][i] == p or grid[1][i] == 'T') and (grid[2][i] == p or grid[2][i] == 'T') and (grid[3][i] == p or grid[3][i] == 'T'):
			return True
	
	#search in first diag
	if (grid[0][0] == p or grid[0][0] == 'T') and (grid[1][1] == p or grid[1][1] == 'T') and (grid[2][2] == p or grid[2][2] == 'T') and (grid[3][3] == p or grid[3][3] == 'T'):
		return True
	
	#search in second diag
	if (grid[0][3] == p or grid[0][3] == 'T') and (grid[1][2] == p or grid[1][2] == 'T') and (grid[2][1] == p or grid[2][1] == 'T') and (grid[3][0] == p or grid[3][0] == 'T'):
		return True
	
	return False
			
n = input()
for i in range(n):
	grid = []
	for j in range(4):
		grid.append(raw_input().strip())
	raw_input()
	xwin = is_win_for('X', grid)
	owin = is_win_for('O', grid)
	filled = is_filled(grid)
	if xwin:
		s = 'X won'
	elif owin:
		s = 'O won'
	elif filled:
		s = 'Draw'
	else:
		s = 'Game has not completed'
	res = 'Case #%d: %s' %(i+1, s)
	print res

	
	