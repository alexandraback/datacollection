import sys

def prime_factors(n):
	f = {2:0,3:0,5:0}
	while n % 5 == 0:
		n /= 5
		f[5] += 1
	while n % 3 == 0:
		n /= 3
		f[3] += 1
	while n % 2 == 0:
		n /= 2
		f[2] += 1
	return f

data = open(sys.argv[1]).readlines()
data.pop(0)
n_sets, n_nums, max_num, n_subsets = map(int, data[0].split())
data.pop(0)
print "Case #1:"

for i in xrange(n_sets):
	nums = map(int, data[i].split())
	max_five = 0
	max_three = 0
	max_two = 0
	min_two = 0
	for n in nums:
		factors = prime_factors(n)
		max_five = max(factors[5], max_five)
		max_three = max(factors[3], max_three)
		max_two = max(factors[2], max_two)
		min_two = max(factors[2], min_two)

	out_string = ""
	for i in xrange(max_five):
		out_string += '5'
	for i in xrange(max_three):
		out_string += '3'
	if min_two == 1:
		out_string += '2'
	for i in xrange(max_two/2):
		if len(out_string) >= 3:
			break
		out_string += '4'
	while len(out_string) < 3:
		if max_five > 0:
			out_string += '5'
		elif max_three > 0:
			out_string += '3'
		else:
			out_string += '2'
	print out_string
