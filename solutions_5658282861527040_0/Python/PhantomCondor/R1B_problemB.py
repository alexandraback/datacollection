import os
import math

def solve(f_in):
	test_case = f_in.readline().split()

	A = int(test_case[0])
	B = int(test_case[1])
	K = int(test_case[2])

	if B > A:
		A = int(test_case[1])
		B = int(test_case[0])


	answer = 0
	for a in range(A):
		for b in range(B):
			if a&b < K:
				answer += 1
	return answer



	

if __name__ == "__main__":
	input_filename = 'B-small-attempt0.in'
	output_filename = 'R1B_B_small_output.txt'

	f_in = open(input_filename)
	counter = 0
	while os.path.isfile(output_filename):
		counter += 1
		output_filename = output_filename.split('.')[0] + str(counter) + '.txt'
	f_out = open(output_filename, 'a')

	test_cases = int(f_in.readline())
	
	for i in range(test_cases):
		ans = solve(f_in)
		f_out.write('Case #' + str(i + 1) +': ' + str(ans) + '\n')

	f_in.close()
	f_out.close()

	print 'Problem completed!'




