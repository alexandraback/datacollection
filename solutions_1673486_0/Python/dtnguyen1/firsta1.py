import sys

def read_input(filename):
	lines = []
	num_lines = 0
	with open(filename) as f:
		for line in f:
			if num_lines == 0:
				num_lines = int(line)*2
			elif len(lines) == num_lines:
				return lines
			else:
				if line[-1] == '\n':
					line = line[:-1]
				lines.append(line)
	return lines

def create_output(results):
    f = open('output.txt', 'w')
    for i in range(len(results)):
		text = "Case #" + str(i+1) + ": {:.6f}".format(results[i])
		print >>f, text

def create_problems(lines):
	problems = []
	for i in range(len(lines)/2):
		line1 = lines[i*2]
		line2 = lines[i*2+1]
		value1 = [int(i) for i in line1.split(' ')]
		value2 = [float(i) for i in line2.split(' ')]
		problems.append((value1[0], value1[1], value2))
	return problems

def solve(problems):
	def keep_typing(typed, total, probs):
		prob = reduce(lambda x,y: x*y, probs, 1)
		remaining = total-typed+1
		correct = remaining*prob
		incorrect = (remaining+total+1)*(1-prob)
		return correct+incorrect
	
	def enter_immediately(total):
		return total+2
	
	def backspace(typed, total, probs, num_backspace):
		prob = reduce(lambda x,y: x*y, probs[:-num_backspace], 1)
		remaining = total-typed+1+num_backspace*2
		correct = remaining*prob
		incorrect = (remaining+total+1)*(1-prob)
		return correct+incorrect
	
	results = []
	for problem in problems:
		typed, total, probs = problem
		expected = []
		for i in range(typed):
			expected.append(backspace(typed, total, probs, i+1))
		expected.append(enter_immediately(total))
		expected.append(keep_typing(typed, total, probs))
		results.append(min(expected))
	return results

if __name__ == '__main__':
	script_name, input_file = sys.argv
	lines = read_input(input_file)
	problems = create_problems(lines)
	results = solve(problems)
	create_output(results)
	