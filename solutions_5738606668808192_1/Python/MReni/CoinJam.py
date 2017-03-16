import math
import random

kb_prime_set = {}
existing_numbers = set()
# largest_in_prime_list = None

# def get_all_prime(cap):
# 	calc_list = range(3, cap, 2)
# 	calc_set = set(calc_list)

# 	count = 0
# 	value = calc_list[0]
# 	while value <= long(math.sqrt(cap)):
# 		multiplier = 2
# 		multi = multiplier * value
# 		while multi <= calc_list[-1]:
# 			if multi in calc_set:
# 				calc_set.remove(multi)
# 				calc_list.remove(multi)
# 			multiplier = multiplier + 1
# 			multi = multiplier * value

# 		count = count + 1
# 		value = calc_list[count]
# 	return calc_list

# def get_all_prime_v2(cap):
# 	calc_list = range(3, cap, 2)
# 	prime_list = []
# 	# count = 0
# 	value = calc_list[0]
# 	while value <= long(math.sqrt(cap)):
# 		prime_list.append(value)
# 		calc_list = [number for number in calc_list if number % value != 0]
# 		# count = count + 1
# 		value = calc_list[0]
# 	return prime_list + calc_list

def get_num_from_string_in_base(string, base):
	value = 0
	for i in range(0, len(string)):
		value = value + long(string[i])*(pow(base, len(string) - i - 1))
	return long(value)

def get_base2_string_from_base10(number):
	return "{0:#b}".format(number)[2:]

# def test_if_prime(number):
# 	if number in kb_prime_set:
# 		return True
# 	else if number < largest_in_prime_list:
# 		return False
# 	else:
# 		# prime test

# 		# add to kb - knowledge 
trace = []

def is_prime(n):
	# if n in kb_prime_set:
	# 	trace.append(kb_prime_set[n])
	# 	return False, kb_prime_set[n]
	if n % 2 == 0 and n > 2: 
		# kb_prime_set[n] = '2'
		# trace.append(kb_prime_set[n])
		return False, '2'

	for i in range(3, min(long(math.sqrt(n)) + 1, 5000), 2):
		if not n % i:
			# kb_prime_set[n] = str(i)
			# trace.append(str(i))
			return False, str(i)
	return True, None
	# return all(n % i for i in range(3, long(math.sqrt(n)) + 1, 2))

def get_coinjam(digits, limit):
	minimum = '1' + '0'*(digits - 2) + '1'
	maximum = '1' + '1'*(digits - 2) + '1'
	# prime_set = set(all_primes)
	count = 0
	while limit > 0:
		x = random.randrange(get_num_from_string_in_base(minimum, 2), get_num_from_string_in_base(maximum, 2) + 1, 2)
		if x in existing_numbers:
			continue
		else:
			existing_numbers.add(x)
	# for x in range(get_num_from_string_in_base(minimum, 2), get_num_from_string_in_base(maximum, 2) + 1, 2):
		# x = random.randrange(get_num_from_string_in_base(minimum, 2), get_num_from_string_in_base(maximum, 2) + 1, 2):
		# count = count + 1
		# if count % 10 == 0:
		# 	print "Tested " + str(count) 
		current_string = get_base2_string_from_base10(x)
		# print "{} -> {} -> {}".format(str(x), str(current_string), get_num_from_string_in_base(current_string, 10))
		trace = []
		prime_flag = False
		for base in range(2,11):
			num = get_num_from_string_in_base(current_string, base)
			tested_prime, divider = is_prime(num)
			if tested_prime:
				prime_flag = True
				break
			# else:
			# 	test_num = get_num_from_string_in_base(current_string + current_string[::-1], base)
			# 	test_result, test_div = is_prime(test_num)
			# 	if test_result:
			# 		print "DOES NOT WORK"
			# trace.append(str(num) + "/" + divider + "=" + str(num/long(divider)))
			trace.append(divider)
		# prime_flag = any(is_prime(get_num_from_string_in_base(current_string, base)) for base in range(2,11))
		if prime_flag:
			continue
		# print str(prime_flag)
		# print trace
		print current_string + " " + " ".join(trace)
		limit = limit - 1
		if limit <= 0:
			return

# count = 1
# with open('dataC', 'rb') as data:
# 	for number in data:
# 		print "Case #" + str(count) + ": " + str(get_min_count(long(number))) 
# 		count = count + 1
digits = 32
limit = 500
# all_primes = get_all_prime_v2(long(math.pow(2, digits)))
# largest_in_prime_list = all_primes[-1]
# kb_prime_set = set(all_primes)
print "Case #1:"
get_coinjam(digits, limit)