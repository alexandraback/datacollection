##
## CodeJam Code Template
## Ameer Ayoub <ameer.ayoub@gmail.com>
##

# Imports
from sys import argv

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
# ASSUMED KBLOCKS SORTED
def choose_ken(kblocks, told_naomi):
	# we basically find the smallest thing in our list that beats told_naomi otherwise
	# we choose the smallest thing in the list because we can't beat her
	# print kblocks, told_naomi
	# RETURNS TRUE IF HE WINS
	# FALSE IF HE LOSSES
	for i in range(len(kblocks)):
		if kblocks[i] > told_naomi:
			kchosen = kblocks[i]
			kblocks.remove(kchosen)
			return True
	kmin = min(kblocks)
	kblocks.remove(kmin)
	return False

def smallest_over(nblocks, chosen_ken):
	for i in range(len(nblocks)):
		if nblocks[i] > chosen_ken:
			return i
	return -1

def solve_case(kblocks, nblocks):
	kb = sorted(kblocks)
	nb = sorted(nblocks)
	# legit strat
	np1 = 0
	for n in nb:
		r = choose_ken(kb, n)
		if not r:
			np1 += 1
	# cheater strat
	# tell him something big so he throws out stuff
	# at which point we just pick the smallest thing that beats his next smallest thing
	kb = sorted(kblocks)
	np2 = 0
	while len(kb) > 0:
		# if I have something bigger than his lowest then I play that
		j = smallest_over(nb, min(kb))
		if j != -1:
			told = max(kb) + 1
			choose_ken(kb, told) # will remove
			nb.remove(nb[j])
			np2 += 1
		else:
			break
	return np2,np1

def solution():
	global problem, fin, fout
	print "Starting Problem", problem, size

	N = ri()
	for n in xrange(N):
		print_progress_bar(n, N)
		number_of_entries = ri()
		nblocks = rfl()
		kblocks = rfl()
		#print kblocks, nblocks
		result = solve_case(kblocks, nblocks)
		r = str(result[0]) + " " + str(result[1])
		write_result(n, r)

if __name__ == "__main__":
	solution()