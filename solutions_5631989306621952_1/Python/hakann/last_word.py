
def last_word(str):
	list_str = list(str)
	result_list = []
	first_letter = list_str[0]
	result_list.append(first_letter)
	for letter in list_str[1:]:
		if letter >= first_letter:
			result_list.insert(0, letter)
			first_letter = letter
		else:
			result_list.append(letter)
	return ''.join(result_list)

def formatted_output(index, final_count):
    return 'Case #' + str(index) + ': ' + str(final_count)


t = int(raw_input())  
for i in range(1, t + 1):
    m = raw_input()
    print formatted_output(i, last_word(m))