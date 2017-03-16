import Queue
import numpy

def print_spiral(ar):
	rows, cols = len(ar), len(ar[0])
	r, c = 0, -1 # start here
	nextturn = stepsx = cols # move so many steps
	stepsy = rows-1
	inc_c, inc_r = 1, 0 # at each step move this much
	turns = 0 # how many times our snake had turned
	for i in range(rows*cols):
		c += inc_c
		r += inc_r 		
		print ar[r][c],
		if i == nextturn-1:
			turns += 1
			# at each turn reduce how many steps we go next
			if turns%2==0:
				nextturn += stepsx
				stepsy -= 1
			else:
				nextturn += stepsy
				stepsx -= 1
				# change directions
			inc_c, inc_r = -inc_r, inc_c  

def new_init_grid(grid,C,M):
	count=0
	m = (M/C)*C
	I=-1
	for i in range(len(grid)):
		for j in range(C):
			if count < m:
				grid[i].append('*')
				I=i
				J=j
			else:
				grid[i].append('.')
			count=count+1
	count=m
	#print count, M, m, I, J
	for j in range(C):
		for i in range(I+1,len(grid)):
			if count < M:
				grid[i][j]='*'
				count=count+1
	grid=numpy.array(grid)
	#print grid
	return grid

def init_grid(grid,C,M):
	count=0
	if M > C:
		m=((M/C)-1)*C
	else:
		m = (M/C)*C
	I=-1
	for i in range(len(grid)):
		for j in range(C):
			if count < m:
				grid[i].append('*')
				I=i
				J=j
			else:
				grid[i].append('.')
			count=count+1
	count=m
	#print count, M, m, I, J
	for j in range(C):
		for i in range(I+1,len(grid)):
			if count < M:
				grid[i][j]='*'
				count=count+1
	grid=numpy.array(grid)
	#print grid
	return grid

#def test_init_grid(grid,C,M):
#	count=0
	#	    for (int i = n - 1; i >= 0; i--) {
	#					        for (int j = 0; j < i; j++) {
#											            print array[n - i + j][n - j - 1];
#																	        }
#										        newline;
#														    }

#	for i in range(len(grid)):
#		for j in range(C):
#				grid[i].append('.')

#	for i in range(len(grid)):
#		for j in range(i+1):
#			if count<M:
#				grid[j][i-j]='*'
#				count=count+1
	
#	while

def getNeighbourMines(grid,i,j,R,C):
	count=0
	for x in range(i-1,i+2):
		for y in range(j-1,j+2):
			if x>=0 and y>=0 and x<R and y<C and grid[x][y]=='*':
				count=count+1
	return count
	
def process_grid(grid,R,C):
	q=Queue.Queue()
	q.put([R-1,C-1]) # initial starting
	while not q.empty():
		indx=q.get()
		grid[indx[0]][indx[1]]=getNeighbourMines(grid,indx[0],indx[1],R,C)
		if grid[indx[0]][indx[1]]=='0':
			#print indx[0],indx[1],range(indx[0]-1,indx[0]+2), range(indx[1]-1,indx[
			for i in range(indx[0]-1,indx[0]+2):
				for j in range(indx[1]-1,indx[1]+2):
					if i>=0 and j>=0 and i<R and j<C and grid[i][j]=='.':
						grid[i][j]='i'
						q.put([i,j])
	return grid
def main():
	T=input()
	for i in range(T):
		s=raw_input()
		(R,C,M)=map(int, s.strip().split(' '))
		grid=[[] for j in range(R)]
		grid=init_grid(grid,C,M)
		igrid=numpy.array(grid)
		grid=process_grid(grid,R,C)
		flag=numpy.where(grid=='.')
		igrid[R-1][C-1]='c'
		print 'Case #'+str(i+1)+':'
		f=True
		if M==R*C:
			print 'RAGHUDEEP'
			f=False
		if len(flag[0])==0 and f:
			#print igrid
			print '\n'.join(''.join(str(cell) for cell in row) for row in igrid)
			f=False
		(C,R,M)=map(int, s.strip().split(' '))
		grid=[[] for j in range(R)]
		grid=init_grid(grid,C,M)
		igrid=numpy.array(grid)
		grid=process_grid(grid,R,C)
		flag=numpy.where(grid=='.')
		igrid[R-1][C-1]='c'
		if f:
			if len(flag[0])==0:
				print '\n'.join(''.join(str(cell) for cell in row) for row in igrid)
				f=False
		(R,C,M)=map(int, s.strip().split(' '))
		grid=[[] for j in range(R)]
		grid=new_init_grid(grid,C,M)
		igrid=numpy.array(grid)
		grid=process_grid(grid,R,C)
		flag=numpy.where(grid=='.')
		igrid[R-1][C-1]='c'
		if f:
			if len(flag[0])==0:
				print '\n'.join(''.join(str(cell) for cell in row) for row in igrid)
				f=False
			else:
				print 'Impossible'

		
if __name__ == "__main__": 
	main()
