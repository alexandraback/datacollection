DIGITS = ['ZERO', 'ONE', 'TWO', 'THREE', 'FOUR',
'FIVE', 'SIX', 'SEVEN', 'EIGHT', 'NINE']

def get_amount_of_digit(chars, digit, letter_to_search):
	amount = chars.count(letter_to_search)
	for letter in DIGITS[digit]:
		for i in range(amount):
			chars.remove(letter)
	return amount

def update_result(chars, result_dict, digit, letter_to_search):
	amount = get_amount_of_digit(chars, digit, letter_to_search)
	result_dict[digit] = amount

def get_final_result(result_dict):
	final_result = ""
	for digit in result_dict:
		for i in range(result_dict[digit]):
			final_result += str(digit)
	return final_result

def operation(inp):
	sorted_chars = sorted(inp)
	result = {}
	update_result(sorted_chars, result, 0, 'Z')
	update_result(sorted_chars, result, 2, 'W')
	update_result(sorted_chars, result, 4, 'U')
	update_result(sorted_chars, result, 6, 'X')
	update_result(sorted_chars, result, 8, 'G')
	update_result(sorted_chars, result, 3, 'H')
	update_result(sorted_chars, result, 5, 'F')
	update_result(sorted_chars, result, 1, 'O')
	update_result(sorted_chars, result, 7, 'S')
	update_result(sorted_chars, result, 9, 'I')
	return get_final_result(result)

amount_of_inputs = input()
for index in range(amount_of_inputs):
	current_input = raw_input()
	case_result = operation(current_input)
	print("Case #%s: %s" % (index + 1, case_result))
