import sys
import math
from decimal import *

filename = sys.argv[1]
f = open(filename, 'r')

numCases = int(f.readline())

for t in range(numCases):
	B, M = map(int, f.readline().split())
	possible = True
	MAX = 2**(B-2)
	output_str = ''
	matrix_str = ''
	if M > MAX:
		possible = False
		output_str = 'IMPOSSIBLE'
	if possible:
		output_str = 'POSSIBLE\n'
		for i in range(1, B):
			matrix_str = matrix_str + '0'*(i+1) + '1'*(B-i-1) + '\n'
		if MAX == M:
			# max case
			matrix_str = '0' + '1'*(B-1) + '\n' + matrix_str
		else:
			first_row = ''
			while M > 0:
				bit = M%2
				M = M/2
				first_row = str(bit) + first_row
			matrix_str = '0' + '0'*(B - len(first_row) - 2) + first_row + '0\n' + matrix_str

	print_str = 'Case #{}: {}'.format(t+1, (output_str+matrix_str).strip())
	print print_str