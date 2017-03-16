def check_row(grid, row, col):
	height = grid[row][col]
	
	for elem in grid[row]:
		if elem > height:
			return False
	
	return True
	
def check_col(grid, row, col):
	height = grid[row][col]
	
	for row in grid:
		if row[col] > height:
			return False
	
	return True


num_test_cases = int(raw_input()) + 1

for num in xrange(1, num_test_cases):
	n,m = [int(x) for x in raw_input().split()]
	
	grid = []
	for i in xrange(0,n):
		grid.append([int(x) for x in raw_input().split()])
	is_possible = True
	for i in xrange(0,n):
		if is_possible == False:
			break
		for j in xrange(0,m):
			is_possible = check_row(grid, i, j) or check_col(grid, i, j)
			if is_possible == False:
				break
	
	if is_possible == True:
		print 'Case #%s: %s' % (num, "YES")
	else:
		print 'Case #%s: %s' % (num, "NO")