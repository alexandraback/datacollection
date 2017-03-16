#!/usr/bin/python

import string
digs = string.digits + string.letters

def primes(n):
	if n==2: return [2]
	elif n<2: return []
	s=range(3,n+1,2)
	mroot = n ** 0.5
	half=(n+1)/2-1
	i=0
	m=3
	while m <= mroot:
		if s[i]:
			j=(m*m-3)/2
			s[j]=0
			while j<half:
				s[j]=0
				j+=m
		i=i+1
		m=2*i+3
	return [2]+[x for x in s if x]

pri = primes(99999)

def int2base(x, base):
	if x < 0: sign = -1
	elif x == 0: return digs[0]
	else: sign = 1
	x *= sign
	digits = []
	while x:
		digits.append(digs[x % base])
		x /= base
	if sign < 0:
		digits.append('-')
	digits.reverse()
	return ''.join(digits)

def solve(max_chars, numbers_count):
	#print "max_chars: " + str(max_chars)
	#print "numbers_count: " + str(numbers_count)
	result = "\n"
	i = 0
	current_num_str = "1" + "0" * (max_chars - 2) + "1"
	while i < numbers_count and len(current_num_str) == max_chars:
		#print "before current_num_str: " + current_num_str
		num_works = True
		p_list = []
		for base in xrange(2, 11):
			#print "checking base: " + str(base)
			base_num = int(current_num_str, base)
			base_works = False
			#print "base num: " + str(base_num)
			for p in pri:
				if base_num <= p:
					continue
				if 0 == base_num % p:
					#print "prime works: " + str(p)
					base_works = True
					p_list.append(p)
					break
			if not base_works:
				num_works = False
				break

		if num_works:
			i += 1
			result += current_num_str
			for p in p_list:
				result += " " + str(p)
			if i != numbers_count:
				result += "\n"
			#print "found result!!: " + current_num_str
		#print "after current_num_str: " + current_num_str
		base_2_number = int(current_num_str, 2)
		base_2_number += 2
		current_num_str = int2base(base_2_number, 2)
	if len(current_num_str) > max_chars:
		assert False
	return result

import sys
input_lines = open(sys.argv[1], "rt").readlines()
stripped_input_lines = [line.strip() for line in input_lines]
num_tests = int(input_lines[0])
#print num_tests

i = 1
for line in stripped_input_lines[1:]:
	max_chars = int(line.split()[0])
	numbers_count = int(line.split()[1])
	result = solve(max_chars, numbers_count)
	print "Case #" + str(i) + ": " + str(result)
	i += 1
