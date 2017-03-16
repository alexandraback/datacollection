import sys

def check(grid, s, isRow, idx):
	hasZero = False
	for i in range(len(grid)):
		if isRow:
			if grid[idx][i] == s[i]:
				pass
			elif grid[idx][i] == 0:
				hasZero = True
				if (idx == 0 or (s[i] > grid[idx-1][i])) and (idx == len(grid) - 1 or (s[i] < grid[idx+1][i])):
					pass
			
			else: return False
		else:
			if grid[i][idx] == 0: hasZero = True
			if grid[i][idx] == s[i] or grid[i][idx] == 0:
				pass
			else: return False
			
			
			if grid[i][idx] == s[i]:
				pass
			elif grid[i][idx] == 0:
				hasZero = True
				if (idx == 0 or (s[i] > grid[i][idx-1])) and (idx == len(grid) - 1 or (s[i] < grid[i][idx+1])):
					pass
			
			else: return False
			
	return True

def zz(grid):
	for i in grid:
		for j in i:
			if j == 0: return True
	else: return False

def recurse(grid, rc, n, rrr, ccc):
	
	if zz(grid) == False and len(rc) == 0:
		return grid
	

	for idx in range(n):
		test = check(grid, rc[0], False, idx)
		if test and ccc[idx] == False:
			ng = [row[:] for row in grid]
			for j in range(len(grid)):
				ng[j][idx] = rc[0][j]
				
			rrrr = rrr[:]
			cccc = ccc[:]
			cccc[idx] = True
			q = recurse(ng, rc[1:], n, rrrr, cccc)
			if q != False:
				return q
				
		test = check(grid, rc[0], True, idx)
		if test and rrr[idx] == False:
			ng = [row[:] for row in grid]
			for j in range(len(grid)):
				ng[idx][j] = rc[0][j]
				
			rrrr = rrr[:]
			cccc = ccc[:]
			rrrr[idx] = True
			q = recurse(ng, rc[1:], n, rrrr, cccc)
			if q != False:
				return q
				
			
	
	return False
			


def solve(rc, n):
	
	grid = [[0]*n for i in range(n)]
	grid[0] = rc[0]

	c = recurse(grid, rc[1:], n, [False]*n, [False]*n)

	s = []
	for i in range(n):
		s.append(tuple(c[i]))
		s.append(tuple(c[j][i] for j in range(n)))
		


	for i in rc:
		j = tuple(i)
		s.remove(j)
		
	return s[0]
			

N = int(raw_input())

case = 1
for i in range(N):
	size = int(raw_input())
	
	rc = []
	for i in range(size*2 -1):
		rc.append([int(j) for j in raw_input().split()])
	
	if True:
		rc.sort()
		sol = solve(rc, size)
		print ("Case #%d:" % case), " ".join(str(i) for i in sol)
	case += 1
