import sys
from mpmath import *

# use external library mpmath https://code.google.com/p/mpmath/

if len(sys.argv) < 3:
	print 'input/output file name must be defined.'
	exit(1)

input_file = open(sys.argv[1])
output_file = open(sys.argv[2], 'w')
num = int(input_file.readline())
for i in range(num):
	input_text = input_file.readline().split()
	r = int(input_text[0])
	t = int(input_text[1])
	a = r + 1
	mp.dps = 100
	ans = (3 - 2 * a + sqrt(4 * a * a - 12 * a + 9 + 8 * t)) / 4

	output_file.write('Case #' + str(i + 1) + ': ' + str(int(ans)) + '\n')

input_file.close()
output_file.close()