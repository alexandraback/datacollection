# Using the 3rd party library "gmpy2"
# gmpy2 is covered under the GNU LGPL license and
# can be downloaded from http://code.google.com/p/gmpy/
import gmpy2
from gmpy2 import mpz

import math
import sys


# Read data file into a list
lines = []
with open(sys.argv[1], "r", encoding="utf-8") as data_file:
	for line in data_file:
		lines.append(line.rstrip('\n'))
		
		
# Get total number of test cases
test_cases = int(lines[0])
del lines[0]


# Process each test case
case = 0
for line in lines:
	
	case += 1
	
	# Obtain input data
	x = int(line.split(" ")[0])
	y = int(line.split(" ")[1])
	
	cur_x = 0
	cur_y = 0
	
	moves = []
	jump = 1
	
	# First, x-axis
	while not cur_x == x:
		if cur_x < x:
			moves.append('W')
			moves.append('E')
			cur_x += 1
		else:
			moves.append('E')
			moves.append('W')
			cur_x -= 1
	
	# Now, y-axis
	while not cur_y == y:
		if cur_y < y:
			moves.append('S')
			moves.append('N')
			cur_y += 1
		else:
			moves.append('N')
			moves.append('S')
			cur_y -= 1
			
	

	print("Case #" + str(case) + ": " + str(''.join(moves)))