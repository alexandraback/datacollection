def solve(topics):
	left_words = {}
	right_words = {}

	for topic in topics:
		left_word = topic[0]
		right_word = topic[1]

		if left_word not in left_words:
			left_words[left_word] = 0
		if right_word not in right_words:
			right_words[right_word] = 0
		left_words[left_word] += 1
		right_words[right_word] += 1

	fake_count = 0
	done = False
	while not done:
		done = True
		for topic in topics:
			left_word = topic[0]
			right_word = topic[1]
			if left_words.get(left_word, 0) > 1 and right_words.get(right_word, 0) > 1:
				fake_count += 1
				left_words[left_word] -= 1
				right_words[right_word] -= 1
				done = False


	return fake_count

def read_input(filename):
	with open('output.txt', 'w') as output_file:
		with open(filename) as input_file:
			T = int(input_file.readline())
			for i in range(T):
				N = int(input_file.readline())
				topics = []
				for j in range(N):
					topics.append(input_file.readline().strip().split(' '))
				output_file.write('Case #{:d}: {:d}\n'.format(i + 1, solve(topics)))

read_input('C-small-attempt0.in')