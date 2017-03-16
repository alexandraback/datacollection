def solve(word):
	new_word = word[0]
	for char in word[1:]:
		if new_word[0] > char:
			new_word = new_word + char
		else:
			new_word = char + new_word
	return new_word



T = input()
for i in range(T):
	word = raw_input()
	print 'Case #' + str(i + 1) + ': ' + str(solve(word))