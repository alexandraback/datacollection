import math

ALL_DIGIT = set([0, 1, 2, 3, 4, 5, 6, 7, 8, 9])
MAX_ROUND = 100000
GIVEUP = "INSOMNIA"

def has_all_digit(digits):
	for digit in ALL_DIGIT:
		if digit not in digits:
			return False
	return True

def fill_digits(digits, number):
	if number < 10:
		digits.add(number)
	else:
		digits.add(number%10)
		fill_digits(digits, math.floor(number/10))

def get_min_count(number):
	if number == 0:
		return GIVEUP
	digits = set()
	multiplier = 0
	while (not has_all_digit(digits)) or (multiplier < MAX_ROUND):
		multiplier = multiplier + 1
		current_number = number * multiplier
		fill_digits(digits, current_number)
		if has_all_digit(digits):
			return current_number
	return GIVEUP

count = 1
with open('dataAlarge', 'rb') as data:
	for number in data:
		print "Case #" + str(count) + ": " + str(get_min_count(int(number))) 
		count = count + 1