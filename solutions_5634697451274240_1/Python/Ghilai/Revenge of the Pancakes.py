
FILE_PATH = "B-large.in"
OUTPUT_FILE_PATH = 'B-large.out'

def read_file(path):
	with open(path, 'rb') as f:
		lines = f.readlines()
		test_cases = [line for line in lines[1:]]
		for (i, test_case) in enumerate(test_cases):
			if test_case.endswith('\n'):
				test_cases[i] = test_case[:-1]
	print test_cases
	return test_cases

def output_solution(solution, path):
	lines = []
	with open(path, 'wb') as f:
		for (i, sol) in enumerate(solution):
			lines += ['Case #{index}: {solution}\n'.format(index=i+1, solution=sol)]
		f.writelines(lines)
	
def solve_test_case(stack):
	count = 0
	for i in xrange(len(stack) - 1):
		if stack[i] != stack[i+1]:
			count += 1
	if stack[-1] == '-':
		count += 1
	return count
	
if __name__ == "__main__":
	test_cases = read_file(FILE_PATH)
	solution = [solve_test_case(test_case) for test_case in test_cases]
	print solution
	output_solution(solution, OUTPUT_FILE_PATH)