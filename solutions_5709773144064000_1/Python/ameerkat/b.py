##
## CodeJam Code Template
## Ameer Ayoub <ameer.ayoub@gmail.com>
##

# Imports
from sys import argv
from decimal import *

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
	# global is_practice, problem, size
	# practice_string = "-practice" if is_practice else "-attempt"
	# num = "" 
	# if not is_practice and size != "sample":
	# 	num = argv[2]
	# return open(problem + "-" + size + practice_string + num + ".in", "r")
	return open("B-large.in")

def output_file():
	# global is_practice, problem, size
	# practice_string = "-practice" if is_practice else "-attempt"
	# num = "" 
	# if not is_practice and size != "sample":
	# 	num = argv[2]
	# return open(problem + "-" + size + practice_string + num + ".out.txt", "w")
	return open("B-large.out.txt", "w")

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
def r(): # read
	global fin
	return fin.readline().strip()
def rnl(n): # read n lines
	global fin
	l = []
	for ni in xrange(n):
		l.append(fin.readline().strip())
	return l

##
## Specific Problem Solution
##

def solve_case(c,f,x):
	# print c,f,x
	rate = 2.0
	t = 0.0
	while True:
		if (x/rate) <= ((c/rate)+(x/(rate + f))):
			t += (x/rate)
			break
		else:
			t += (c/rate)
			rate += f
	return t


def solution():
	global problem, fin, fout
	print "Starting Problem", problem, size

	N = ri()
	for n in xrange(N):
		print_progress_bar(n, N)
		C,F,X = rfl()
		result = solve_case(C,F,X)
		write_result(n, result)

if __name__ == "__main__":
	getcontext().prec = 28
	solution()