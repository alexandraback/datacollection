#!/usr/bin/python
import sys

def main(size):
	"""
	@param size = string; small or large
	"""
	infile = size + "_a.in"

	output = ""

	with open(infile) as file:
		num_cases = int(file.readline())
		for case in range(1, num_cases+1):
			phone_number = decode_phone_number(file.readline())
			output += "Case #%s: %s\n" % (case, phone_number)

	with open(size + "_a.out", 'w') as outfile:
		outfile.write(output)


def decode_phone_number(string):
    number_of_digits = {i: 0 for i in range(10)}
    number_of_digits[0] = string.count("Z")
    string_numbers = {0:"ZERO", 1:"ONE", 2:"TWO", 3:"THREE", 4:"FOUR", 5:"FIVE",
                      6:"SIX", 7:"SEVEN", 8:"EIGHT", 9:"NINE"}
    reference_chars = {0:"Z", 2:"W", 6:"X", 7:"S", 5:"V", 8:"G", 3:"T",
                       4:"R", 1:"O", 9:"I"}
    ordered_numbers = [0, 2, 6, 8, 7, 5, 3, 4, 1, 9]
    for i in ordered_numbers:
        number_of_digits[i] = string.count(reference_chars[i])
        for char in string_numbers[i]:
            string = string.replace(char, "", number_of_digits[i])

    number = ""
    for i in range(10):
        number += str(i)*number_of_digits[i]
    return number

if __name__ == "__main__":
	main(sys.argv[1])


