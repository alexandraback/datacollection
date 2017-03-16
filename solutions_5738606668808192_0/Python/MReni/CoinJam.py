import math

kb_prime_set = {}
# largest_in_prime_list = None

# def get_all_prime(cap):
# 	calc_list = range(3, cap, 2)
# 	calc_set = set(calc_list)

# 	count = 0
# 	value = calc_list[0]
# 	while value <= int(math.sqrt(cap)):
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
# 	while value <= int(math.sqrt(cap)):
# 		prime_list.append(value)
# 		calc_list = [number for number in calc_list if number % value != 0]
# 		# count = count + 1
# 		value = calc_list[0]
# 	return prime_list + calc_list

def get_num_from_string_in_base(string, base):
	value = 0
	for i in range(0, len(string)):
		value = value + int(string[len(string) - i - 1])*math.pow(base, i)
	return int(value)

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
	if n in kb_prime_set:
		trace.append(kb_prime_set[n])
		return False, kb_prime_set[n]
	if n % 2 == 0 and n > 2: 
		kb_prime_set[n] = '2'
		trace.append(kb_prime_set[n])
		return False, '2'

	for i in range(3, int(math.sqrt(n)) + 1, 2):
		if not n % i:
			kb_prime_set[n] = str(i)
			trace.append(str(i))
			return False, str(i)
	return True, None
	# return all(n % i for i in range(3, int(math.sqrt(n)) + 1, 2))

def get_coinjam(digits, limit):
	minimum = '1' + '0'*(digits - 2) + '1'
	maximum = '1' + '1'*(digits - 2) + '1'
	# prime_set = set(all_primes)

	for x in range(get_num_from_string_in_base(minimum, 2), get_num_from_string_in_base(maximum, 2) + 1, 2):
		current_string = get_base2_string_from_base10(x)
		trace = []
		prime_flag = False
		for base in range(2,11):
			num = get_num_from_string_in_base(current_string, base)
			tested_prime, divider = is_prime(num)
			if tested_prime:
				prime_flag = True
				break
			# trace.append(str(num) + "/" + divider + "=" + str(num/int(divider)))
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
# 		print "Case #" + str(count) + ": " + str(get_min_count(int(number))) 
# 		count = count + 1
digits = 16
limit = 50
# all_primes = get_all_prime_v2(int(math.pow(2, digits)))
# largest_in_prime_list = all_primes[-1]
# kb_prime_set = set(all_primes)
get_coinjam(digits, limit)