#Author : Sumit Mahamuni
#email  : sumit143smailbox@gmail.com

import sys

inputfile_name = sys.argv[1]

def move_to_east(X, N):
	return X + N

def move_to_west(X, N):
	return X - N

def move_to_north(Y,N):
	return Y + N

def move_to_south(Y,N):
	return Y - N

def is_east_possible(startX, X):
	return (startX <= X)	

def is_north_possible(startY, Y):
	return (startY <= Y)	
	

def find_path(X,Y):
	startX, startY = (0,0)
	step = 0
	path = []
	while(startX != X):
		step += 1
		if(is_east_possible(move_to_east(startX, step), X)):
			startX = move_to_east(startX, step)
			path.append('E')
		else:
			startX = move_to_west(startX, step)
			path.append('W')

	while(startY != Y):
		step += 1
		if(is_north_possible(move_to_north(startY, step), Y)):
			startY = move_to_north(startY, step)
			path.append('N')
		else:
			startY = move_to_south(startY, step)
			path.append('S')
	return "".join(path)

with open(inputfile_name) as infile:
	T = int(infile.readline())

	for case in range(0,T):
		_first_line = infile.readline()
		X, Y = map((lambda x: int(x)), _first_line.split(' '))
		print "Case #%d:" % (case+1),
		print find_path(X,Y)
		