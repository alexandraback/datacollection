##
## CodeJam Code Template
## Ameer Ayoub <ameer.ayoub@gmail.com>
##

# Imports
from sys import argv
import time
import itertools

def get_problem():
	return argv[0].split('.')[0].upper()

def get_size():
	if len(argv) < 2:
		return "sample"
	else:
		return argv[1]

##
## Problem Definition
is_practice = False
problem = get_problem()
size = get_size()
debug = False
##
##

# Helper Functions
def input_file():
	global is_practice, problem, size
	practice_string = "-practice" if is_practice else "-attempt"
	num = "" 
	if not is_practice:
		num = argv[2]
	return open(problem + "-" + size + practice_string + num + ".in", "r")

def output_file():
	global is_practice, problem, size
	practice_string = "-practice" if is_practice else "-attempt"
	num = "" 
	if not is_practice:
		num = argv[2]
	return open(problem + "-" + size + practice_string + num + ".out.txt", "w")

# file definitions
fin = input_file()
fout = output_file()

def write_result(n, result):
	global size, fout
	if size == "sample" or debug:
		print "Case #" + str(n+1) + ": " + str(result)
	fout.write("Case #" + str(n+1) + ": " + str(result) + "\n")

def print_progress_bar(n, N):
	if size == "sample":
		return
	progress = (float(n+1)/N)*100
	progress_bar_inner = '=' * int(progress/10)
	space_fill = ' ' * (10 - len(progress_bar_inner))
	print "\r" + str(int(progress)) + "% => [" + progress_bar_inner + space_fill + "]",

def ri(): # read int
	global fin
	return int(fin.readline().strip())
def ril(): # read int list
	global fin
	return map(int, fin.readline().strip().split(' '))
def rf(): # read float
	global fin
	return float(fin.readline().strip())
def rfl(): # read float
	global fin
	return map(float, fin.readline().strip().split(' '))
def rnl(n): # read n lines
	global fin
	l = []
	for ni in xrange(n):
		l.append(fin.readline().strip())
	return l

##
## Specific Problem Solution
##

def touching_zero(b,i,j,r,c):
	if i > 0:
		if b[i-1][j] == 0: # above
			return True
		if j > 0:
			if b[i-1][j-1] == 0: # top left
				return True
		if j < c-1:
			if b[i-1][j+1] == 0: # top right
				return True
	if j > 0:
		if b[i][j-1] == 0: # left
			return True
		if i < r-1:
			if b[i+1][j-1] == 0: # bottom left
				return True
	if j < c-1:
		if b[i][j+1] == 0: # right
			return True
		if i < r-1:
			if b[i+1][j+1] == 0: # bottom right
				return True
	if i < r-1:
		if b[i+1][j] == 0: # bottom
				return True

def solve_case(r,c,m):
	if c == 1 and r == 1:
		return [['c']] # m must be 0
	if m == ((r*c) - 1):
		exact = True
		board = []
		b = ['*'] * c
		for i in range(r):
			board.append(b[:])
		board[0][0] = 'c'
		return board
	board = []
	b = ['.'] * c
	for i in range(r):
		board.append(b[:])
	for comb in itertools.combinations(range(r*c), m):
		# clear board
		for i in range(r):
			for j in range(c):
				board[i][j] = 0
		for co in comb:
			i = co/c
			j = co%c
			board[i][j] = '*'
			# fill in numbers
			if i > 0:
				if board[i-1][j] != '*': # above
					board[i-1][j] += 1
				if j > 0:
					if board[i-1][j-1] != '*': # top left
						board[i-1][j-1] += 1
				if j < c-1:
					if board[i-1][j+1] != '*': # top right
						board[i-1][j+1] += 1
			if j > 0:
				if board[i][j-1] != '*': # left
					board[i][j-1] += 1
				if i < r-1:
					if board[i+1][j-1] != '*': # bottom left
						board[i+1][j-1] += 1
			if j < c-1:
				if board[i][j+1] != '*': # right
					board[i][j+1] += 1
				if i < r-1:
					if board[i+1][j+1] != '*': # bottom right
						board[i+1][j+1] += 1
			if i < r-1:
				if board[i+1][j] != '*': # bottom
						board[i+1][j] += 1
		# has to have at least 1 zero (since its not complete)
		# if more than one zero, all the zeros have to be touching another zero
		# all the numbers have to touch a zero
		count = 0
		zero_touch_zero = True
		done = False
		for i in range(r):
			if done:
				break
			for j in range(c):
				if board[i][j] == 0:
					count += 1
					if not touching_zero(board, i, j, r, c):
						zero_touch_zero = False
				elif board[i][j] != '*':
					if not touching_zero(board, i, j, r, c):
						done = True
						break
		if (count == 0) or (count > 1 and not zero_touch_zero) or done:
			continue
		# replace a zero with c and replace all the numbers with .
		replaced_zero = False
		for i in range(r):
			for j in range(c):
				if board[i][j] == 0 and not replaced_zero:
					board[i][j] = 'c'
					replaced_zero = True
					continue
				if board[i][j] != '*':
					board[i][j] = '.'
		return board
	return "Impossible"
					


def solution():
	global problem, fin, fout
	print "Starting Problem", problem, size
	start = time.time()

	N = ri()
	for n in xrange(N):
		print_progress_bar(n, N)
		r,c,m = ril()
		result = solve_case(r,c,m)
		fout.write("Case #" + str(n+1) + ":" + "\n")
		if result == "Impossible":
			fout.write(result + "\n")
			continue
		#print result
		for i in range(r):
			for j in range(c):
				fout.write(result[i][j])
			fout.write("\n")
	end = time.time()
	print "Finished in", end - start, "seconds."

if __name__ == "__main__":
	solution()