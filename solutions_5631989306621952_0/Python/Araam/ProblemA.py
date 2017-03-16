if __name__ == '__main__':
	with open('input.txt', 'r') as f:
		with open('output.txt', 'w') as o:
			num_cases = int(f.readline()) + 1
			for case in range(1, num_cases):
				line = f.readline()
				answer = line[0]
				for char in line[1:]:
					if ord(char) >= ord(answer[0]):
						answer = char + answer
					else:
						answer += char
				o.write('Case #{}: {}'.format(case, answer))