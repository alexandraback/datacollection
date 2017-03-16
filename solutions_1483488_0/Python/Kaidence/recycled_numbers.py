#############
# Google Code Jam 2012
# Recycled Numbers by Jos Kraaijeveld
# facebook.com/Kaidenceq @JMKraaijeveld
# kaidence.org
#############

import sys
from math import log10

# Open the files and read the arguments
input = open(sys.argv[1])
output = open(sys.argv[2], 'w')
num_cases = int(input.readline())
current = 1

# Loop over the amount of testcases
while current <= num_cases:
	line = input.readline().split(' ')
	lower, upper = int(line[0]), int(line[1])
	digits = int(log10(lower))+1
	count = 0
	# Loop over the numbers in interval
	while lower <= upper:	
		# For the amount of digits we want to move
		list = []
		for i in range(1, digits):
			# Determine the part to be moved
			moved = (lower % (10**i))
			# Determine the base which should be shifted right
			base = (lower - moved) / (10**i)
			# Determine our m, by combining the moved and base parts
			num = moved*(10**(digits-i)) + base
			# If this is a unique pair, add to count
			if (not num in list) and num > lower and num <= upper:
				list.append(num)
				count += 1
		lower += 1
	output.write("Case #{}: {}\n".format(current, count))
	current += 1	

