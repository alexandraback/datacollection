import math


# def is_prime(num):
	# if num % 2 == 0:
		# return False
	# for i in xrange(3, int(math.sqrt(num)) + 1, 2):
		# if num % i == 0:
			# return False
	# return True
	
def get_div(num):
	if num % 2 == 0:
		return 2
	for i in xrange(3, int(math.sqrt(num)) + 1, 2):
		if num % i == 0:
			return i
	return -1

def coin_jam(bin_num, dividers):
	#import pdb; pdb.set_trace()
	for base in xrange(2,11):
		div = get_div(int(bin_num, base))
		if div == -1:
			return False
		dividers.append(div)
	return True
	
def solve_test_case(N, J):
	root_number = 2**(N-1) + 1
	max_number = 2**N - 1
	coin_jams = []
	for i in xrange(root_number, max_number, 2):
		dividers = []
		is_coin_jam = coin_jam(bin(i)[2:], dividers)
		if is_coin_jam:
			coin_jams.append((i, dividers))
			print coin_jams[-1]
		if len(coin_jams) == 50:
			break
	return coin_jams
	
#if __name__ == "__main__":
	#test_cases = read_file(FILE_PATH)
	#solution = [solve_test_case(test_case) for test_case in test_cases]
	#print solution
	#output_solution(solution, OUTPUT_FILE_PATH)

	
	
	