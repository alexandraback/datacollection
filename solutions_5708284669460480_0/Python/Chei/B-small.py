import itertools

def solve(keys, word, text_length):
	text_count = 0
	max_occurence_in_a_text = 0
	total_occurences = 0
	for text in itertools.product(keys, repeat=text_length):
		text_count += 1
		occurences_in_text = 0
		for start_index in range(text_length - len(word) + 1):
			if "".join(text[start_index:start_index + len(word)]) == word:
				occurences_in_text += 1
		max_occurence_in_a_text = max(occurences_in_text, max_occurence_in_a_text)
		total_occurences += occurences_in_text
	if max_occurence_in_a_text == 0:
		return 0
	return max_occurence_in_a_text * (1 - total_occurences / (text_count * max_occurence_in_a_text))

testcase_count = int(input())
for testcase_index in range(1, testcase_count + 1):
	key_count, word_length, text_length = [int(x) for x in input().split()]
	keys = input()
	word = input()
	result = solve(keys, word, text_length)
	print("Case #%d: %f" % (testcase_index, result))