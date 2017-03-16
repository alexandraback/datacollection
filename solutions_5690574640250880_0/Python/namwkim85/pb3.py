import sys
import math

def chk_bnd(i, j, R, C):
	if i>=0 and i<=(R-1) and j>=0 and j<=(C-1):
		return True
	return False

def find_config(i, j, R, C, M):
	NM  = R*C-M-1
	stack = [[i,j]]
	board = [[0]*C for k in range(R)]
	board[i][j] = 1
	for r in range(R):
		print board[r]
	print '-----------------------'
	while NM>0 and len(stack)>0:
		cell = stack.pop()
		i = cell[0]
		j = cell[1]
		valid_cells = []
		expand = True
		for r in range(-1, 2):
			for c in range(-1, 2):
				if chk_bnd(i+r, j+c, R, C) and board[i+r][j+c]==2:
					expand = False
					break
				if chk_bnd(i+r, j+c, R, C) and board[i+r][j+c]==0:
					valid_cells.append([i+r, j+c])
			if expand==False:
				break
		if expand==False:
			continue

		cell_cnt = len(valid_cells);
		if NM-cell_cnt>=0:
			NM-=cell_cnt
			for k in range(cell_cnt):
				board[valid_cells[k][0]][valid_cells[k][1]] = 1 #visited
		else:
			mine_cnt = abs(NM-cell_cnt)
			for k in range(mine_cnt):
				board[valid_cells[k][0]][valid_cells[k][1]] = 2 #mines
			valid_cells = []
		for r in range(R):
			print board[r]
		print valid_cells
		print '-----------------------'

		for k in range(len(valid_cells)):
			stack.append(valid_cells[k])

	if NM>0:
		return None
	else:
		for r in range(R):
			for c in range(C):
				if board[r][c]==0:
					board[r][c] = 2 
		return board
def main(filename):
	f = open(filename)
	of = open(filename.split('.')[0]+'.out', 'w')
	T = int(f.readline())

	for t in range(T):
		n 	= f.readline().strip().split(' ')
		R 	= int(n[0])
		C 	= int(n[1])
		M 	= int(n[2])
		
		board = []
		ci = -1
		cj = -1
		found = False
		for r in range(R):
			for c in range(C):
				print '========================='
				board = find_config(r, c, R, C, M)
				if board is not None:
					ci = r
					cj = c
					found = True
					break
			if found == True:
				break

		of.write('Case #'+str(t+1) + ':\n')
		if found:
			for r in range(R):
				prt = ''
				for c in range(C):
					if r==ci and c==cj:
						prt += 'c'
					else:
						if board[r][c]==2:
							prt +='*'
						else:
							prt +='.'
				print prt
				of.write(prt + '\n')
		else:
			print 'Impossible'
			of.write('Impossible\n')

	f.close()
	of.close()

if __name__ == '__main__':
	if len(sys.argv)==1:
		print 'missing a filename'
		exit(1)
	main(sys.argv[1])
	sys.exit(0)

