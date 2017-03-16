import sys

def read_input(filename):
	lines = []
	num_lines = 0
	with open(filename) as f:
		for line in f:
			if num_lines == 0:
				num_lines = int(line)
			elif len(lines) == num_lines:
				return lines
			else:
				if line[-1] == '\n':
					line = line[:-1]
				try:
					num_lines += int(line)
					lines.append(line)
				except ValueError:
					lines.append(line)
	return lines

def create_problems(lines):
	problems = []
	problem = []
	levels = 0
	for line in lines:
		try:
			levels = int(line)
			problems.append(problem)
			problem = []
		except ValueError:
			stars = [int(i) for i in line.split(' ')]
			problem.append((stars[0], stars[1]))
	problems.append(problem)
	return problems[1:]

def solve(problems):
	results = []
	for problem in problems:
		levels = len(problem)
		completed = [0]*levels
		current_stars = 0
		rounds = 0
		while current_stars < 2*levels:
			rounds += 1
			gain_two = [i for i in range(levels) if completed[i] == 0 and problem[i][1] <= current_stars]
			gain_one = [i for i in range(levels) if completed[i] == 1 and problem[i][1] <= current_stars]
			ones = [i for i in range(levels) if completed[i] == 0 and problem[i][0] <= current_stars]
			if len(gain_two) > 0:
				i = gain_two[0]
				current_stars += 2
				completed[i] = 2
				if current_stars == 2*levels:
					results.append(rounds)
			elif len(gain_one) > 0:
				i = gain_one[0]
				current_stars += 1
				completed[i] = 2
				if current_stars == 2*levels:
					results.append(rounds)
			elif len(ones) > 0:
				distance = max([problem[i][1]-current_stars for i in ones])
				best = [i for i in ones if problem[i][1]-current_stars == distance]
				i = best[0]
				current_stars += 1
				completed[i] = 1
				if current_stars == 2*levels:
					results.append(rounds)
			else:
				current_stars = 2*levels
				results.append('Too Bad')
	return results

def create_output(results):
    f = open('output.txt', 'w')
    for i in range(len(results)):
		text = "Case #" + str(i+1) + ": " + str(results[i])
		print >>f, text

if __name__ == '__main__':
	script_name, input_file = sys.argv
	lines = read_input(input_file)
	problems = create_problems(lines)
	results = solve(problems)
	create_output(results)
	