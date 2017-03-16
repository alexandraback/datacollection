import math

MAX_PRIME = 100
primes = [p for p in xrange(2, MAX_PRIME+1) if is_prime(p)]

FILE_PATH = 'C-large.in'
OUTPUT_FILE_PATH = 'C-large.out'

def read_file(path):
	with open(path, 'rb') as f:
		lines = f.readlines()
		test_cases = [line for line in lines[1:]]
		for (i, test_case) in enumerate(test_cases):
			if test_case.endswith('\n'):
				test_cases[i] = test_case[:-1]
	return test_cases

def output_solution(solution, path):
	lines = []
	with open(path, 'wb') as f:
		for (i, sol) in enumerate(solution):
			lines += ['Case #{index}:\n'.format(index=i+1)]
			for jam in sol:
				lines += jam + '\n'
		f.writelines(lines)
	
def is_prime(num):
	if num == 2:
		return True
	if num % 2 == 0:
		return False
	for i in xrange(3, int(math.sqrt(num)) + 1, 2):
		if num % i == 0:
			return False
	return True
	
def get_div(num):
	for prime in primes:
		if num % prime == 0:
			return prime
	return None

def coin_jam(bin_num, dividers):
	for base in xrange(2,11):
		div = get_div(int(bin_num, base))
		if div is None:
			return False
		dividers.append(div)
	return True
	
def solve_test_case(test_case):
	N, J = (int(x) for x in test_case.split(' '))
	num = 2**(N-1) + 1
	max_number = 2**N - 1
	coin_jams = []
	while len(coin_jams) < J:
		dividers = []
		is_coin_jam = coin_jam(bin(num)[2:], dividers)
		if is_coin_jam:
			coin_jams.append("{bin_number} {div}".format(bin_number=bin(num)[2:], div=' '.join(map(str, dividers))))
			print coin_jams[-1]
		num += 2	
	return coin_jams
	
if __name__ == "__main__":
	test_cases = read_file(FILE_PATH)
	solution = [solve_test_case(test_case) for test_case in test_cases]
	output_solution(solution, OUTPUT_FILE)
