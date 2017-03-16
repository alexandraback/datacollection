if __name__ == '__main__':
	T = int(raw_input())

	for i in xrange(0, T):
		input_line = raw_input().split()
		keyboard_length = int(input_line[0])
		target_length = int(input_line[1])
		string_length = int(input_line[2])
		keyboard = raw_input()
		target = raw_input()

		charset = {}
		charset_len = 0.0
		for letter in keyboard:
			charset_len +=1
			if charset.has_key(letter) == False:
				charset[letter] = 1
			else:
				charset[letter] += 1

		# print charset_len
		# print charset
		repetitions = string_length/len(target)
		s = target*repetitions + target[:(string_length%len(target))]
		bananas = 0.0
		for j in range(0, len(s)):
			if (s[j:(j+len(target))] == target):
				bananas += 1

		#print (bananas, s)

		prob = 0.0
		if charset.has_key(target[0]):
			prob = float(charset[target[0]])/charset_len
			for tletter in target[1:]:
				if charset.has_key(tletter):
					prob *= float(charset[tletter])/charset_len
				else:
					bananas = 0.0
					break
		else:
			bananas = 0.0

		result = round(bananas - prob*bananas, 7)

		print "Case #%d: %s" %(i+1, result)

