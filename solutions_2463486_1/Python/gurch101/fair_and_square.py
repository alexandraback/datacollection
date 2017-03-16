import math

def digit(num, digit):
	return int(math.floor((num / pow(10, digit)) % 10))
	
def get_next_palindrome(num):
	num_digits = len(str(num))
	
	middle_idx = int(math.floor(num_digits / 2))
	incr = pow(10, middle_idx)
	num = num + incr
	
	num_digits = len(str(num))
	middle_idx = int(math.floor((num_digits - 1) / 2)) + 1
	for d in xrange(0, middle_idx):
		lhd = digit(num, d)
		rhd = digit(num, num_digits - d - 1)
		to_add = 0
		if lhd != rhd:
			to_add = pow(10, d) * (rhd - lhd)
		num = num + to_add
	return num

def is_palindrome(num):
	str_num = str(num)
	return str_num == str_num[::-1]

def get_first_palindrome(num):
	str_num = str(num)
	num_digits = len(str_num)
	middle_idx = int(math.floor((num_digits - 1)/ 2))
	first_half = str_num[0:num_digits - middle_idx - 1]
	if num_digits % 2 == 0:
		return first_half + first_half[::-1]
	else:
		return first_half + str_num[middle_idx] + first_half[::-1]
		
num_test_cases = int(raw_input()) + 1

for num in xrange(1,num_test_cases):
	fair_and_square = set()
	a, b = [int(x) for x in raw_input().split()]
	init_a = a
	a = long(math.floor(math.sqrt(a)))
	b = long(math.floor(math.sqrt(b)))
	
	a = long(get_first_palindrome(a))
	while a <= b:
		if is_palindrome(a):
			x_sq = long(pow(a, 2))
			if x_sq >= init_a and is_palindrome(x_sq):
				fair_and_square.add(x_sq)
		a = get_next_palindrome(a)
	print "Case #%s: %s" % (num, len(fair_and_square))