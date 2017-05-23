
FILE_PATH = "A-large.in"
OUTPUT_FILE_PATH = 'A-large.out'

def read_file(path):
	with open(path, 'rb') as f:
		lines = f.readlines()
		test_cases = [line for line in lines[1:]]
		for (i, test_case) in enumerate(test_cases):
			if test_case.endswith('\n'):
				test_cases[i] = test_case[:-1]
	print test_cases
	return map(int, test_cases)

def output_solution(solution, path):
	lines = []
	with open(path, 'wb') as f:
		for (i, sol) in enumerate(solution):
			lines += ['Case #{index}: {solution}\n'.format(index=i+1, solution=sol)]
		f.writelines(lines)
	
def solve_test_case(num):
	#import pdb; pdb.set_trace()
	if num == 0:
		return 'INSOMNIA'
	digits_seen = set()
	count = 0
	original_num = num
	num = 0
	while len(digits_seen) < 10:
		num += original_num
		digits = [d for d in str(num)]
		for d in digits:
			digits_seen.add(d)
	return num
	
	
	
if __name__ == "__main__":
	test_cases = read_file(FILE_PATH)
	solution = [solve_test_case(test_case) for test_case in test_cases]
	print solution
	output_solution(solution, OUTPUT_FILE_PATH)