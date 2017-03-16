#!/usr/bin/python

import sys

if len(sys.argv) != 2:
	print "usage: ./c.py <input_file_name>"
	exit()

input_file_name = sys.argv[1]
if input_file_name[-3:] == ".in":
	output_file_name = input_file_name[:-3] + ".out"
else:
	output_file_name = input_file_name + ".out"

def extract_decimal(num, base):
	cur_base = 1
	ret = 0
	while num > 0:
		ret += (num % 2) * cur_base
		cur_base *= base
		num /= 2
	return ret

def extract_divisors(num):
	for base in range(2, 11):
		decimal_num = extract_decimal(num, base)
		divisors = []
		i = 2
		while (i * i <= decimal_num):
			if decimal_num % i:
				i += 1
			else:
				divisors.append(i)
				while not decimal_num % i:
					decimal_num /= i
		if decimal_num > 1:
			divisors.append(decimal_num)
		factors[base] = divisors

def find_divisor(num, base):
	for divisor in factors[base]:
		if not num % divisor:
			return divisor
	return 0

results = []
factors = {}
with open(input_file_name, 'r') as f:
	T = int(f.readline())
	for k in range(T):
		tmp = f.readline().split(' ')
		N = int(tmp[0])
		J = int(tmp[1])
		base_num = (1 << (N - 1)) + 1
		extract_divisors(base_num)
		end_num = (1 << (N - 2)) - 1
		result = {}
		count = 0
		i = 0
		while i <= end_num:
			num = (i << 1)
			divisors = []
			for base in range(2, 11):
				divisor = find_divisor(extract_decimal(num, base), base)
				if divisor == 0:
					print "{0:b}".format(num + base_num), base
					break
				else:
					divisors.append(divisor)
			if len(divisors) == 9:
				result[num + base_num] = divisors
				print "{0:b}".format(num + base_num)
				count += 1
				if count == J:
					break
			i += 1
		results.append(result)

with open(output_file_name, 'w') as f:
	for i in range(len(results)):
		output_string = "Case #%d:\n" % (i + 1)
		for num in results[i]:
			output_string += "{0:b}".format(num)
			for j in range(9):
				output_string += " %d" % results[i][num][j]
			output_string += "\n"
		f.write(output_string)
