import time

testcase_count = int(input())

def remove_letters(s, letters):
	for letter in letters:
		s = s.replace(letter, "", 1)
	return s
	
for testcase_index in range(testcase_count):
	text = input()
	result = []
	while len(text) > 0:
		if "Z" in text:
			text = remove_letters(text, "ZERO")
			result.append(0)
			continue
		if "W" in text:
			text = remove_letters(text, "TWO")
			result.append(2)
			continue
		if "X" in text:
			text = remove_letters(text, "SIX")
			result.append(6)
			continue
		if "S" in text:
			text = remove_letters(text, "SEVEN")
			result.append(7)
			continue
		if "V" in text:
			text = remove_letters(text, "FIVE")
			result.append(5)
			continue
		if "F" in text:
			text = remove_letters(text, "FOUR")
			result.append(4)
			continue
		if "O" in text:
			text = remove_letters(text, "ONE")
			result.append(1)
			continue
		if "R" in text:
			text = remove_letters(text, "THREE")
			result.append(3)
			continue
		if "G" in text:
			text = remove_letters(text, "EIGHT")
			result.append(8)
			continue
		if "N" in text:
			text = remove_letters(text, "NINE")
			result.append(9)
			continue
		print("ERROR: " + text + " : " + str(result))
		
	result.sort()
	print("Case #%d: %s" % (testcase_index + 1, "".join(str(x) for x in result)))
	
