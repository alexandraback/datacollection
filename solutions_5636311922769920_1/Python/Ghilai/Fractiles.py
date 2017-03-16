import math 

FILE_PATH = 'D-large.in'
OUTPUT_FILE_PATH = 'D-large.out'

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
			lines += ['Case #{index}: {solution}\n'.format(index=i+1, solution=sol)]
		f.writelines(lines)
	
def solve_test_case(input):
	K, C, S = (int(x) for x in input.split(' '))
	# At each guess we rule out C places for a gold tile.
	guesses_needed = int(math.ceil(K / float(C)))
	if S < guesses_needed:
		return 'IMPOSSIBLE'
	
	# The possible places for a gold tile to be, from 0 to K-1
	possible_places = range(K)
	# The number of tiles we rule out at each guess
	num_guesses = C	
	guesses = []
	guesses_made = 0
	for guess_num in xrange(guesses_needed):
		# The possible places for a tile to be
		tiles_places = possible_places[guesses_made : min(guesses_made + num_guesses, K)]
		guess = 0
		for (i, tiles_place) in enumerate(tiles_places):
			guess += tiles_place * K**(C-i-1)
		guesses.append(guess + 1)
		guesses_made += len(tiles_places)
	return " ".join(map(str, guesses))
	
if __name__ == "__main__":
	test_cases = read_file(FILE_PATH)
	solution = [solve_test_case(test_case) for test_case in test_cases]
	output_solution(solution, OUTPUT_FILE_PATH)