import math

def get_factor(n):
	if n % 2 == 0:
		return 2
	
	for a in xrange(3, min(int(math.ceil(math.sqrt(n))) + 1, 100000)):
		if n % a == 0:
			return a
	return None

def decode_num_in_base(n, base):
	if base == 2:
		return n

	mult = 1
	fin = 0
	while n > 0:
		fin += mult * (n & 1)
		n >>= 1
		mult *= base
	return fin

def get_numbers_and_factors(length, num):
	min_num = (1 << (length - 1)) | 1
	max_num = (1 << (length)) - 1
	numbers = {}
	for a in xrange(min_num, max_num + 1, 2):
		factors = []
		for b in xrange(2, 10+1):
			num_in_base = decode_num_in_base(a, b)
			#print "%s in %d is %d" % (bin(a), b, num_in_base)
			factor = get_factor(num_in_base)
			if None == factor:
				break
			else:
				factors.append(factor)
			#print "%d is a factor of %d" % (factor, num_in_base)
		#print a, factors
		if len(factors) == 9:
			numbers[a] = factors
		if len(numbers) == num:
			break
	return numbers

def main():
	num_tests = int(raw_input())
	for x in xrange(num_tests):
		length, num = [int(a) for a in raw_input().split(' ')]
		numbers_and_factors = get_numbers_and_factors(length, num)
		print "Case #%d:" % (x + 1,)
		for k,v in numbers_and_factors.iteritems():
			print "%s %s" % (bin(k)[2:], ' '.join(str(a) for a in v))

main()