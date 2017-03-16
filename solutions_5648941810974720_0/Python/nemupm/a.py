num_test_cases = input()
UPPER_CASE = "ZWXGHRFSITO"
UPPER_CASE_LETTERS = [
"ZERO", "TWO", "SIX", "EIGHT", "THREE", "FOUR", "FIVE", "SEVEN", "NINE", "TEN", "ONE"]
UPPER_CASE_DIGIT = [0,2,6,8,3,4,5,7,9,10,1]

for nc in xrange(1, num_test_cases+1):
	upper_case_count = {}
	digits = []
	for letters in UPPER_CASE_LETTERS:
		for char in letters:
			upper_case_count[char] = 0
	for char in raw_input():
		upper_case_count[char] += 1
	for i, char in enumerate(UPPER_CASE):
		i_count = upper_case_count[char]
		if i_count == 0:
			continue
		digits.append(("%d" % UPPER_CASE_DIGIT[i]) * i_count)
		for remove_char in UPPER_CASE_LETTERS[i]:
			upper_case_count[remove_char] -= i_count
	digits.sort()
	ans = ""
	for digit in digits:
		ans += digit
	print "Case #%d: %s" % (nc, ans)