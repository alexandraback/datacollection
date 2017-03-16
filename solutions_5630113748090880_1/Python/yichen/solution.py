def solve(case_number):
	size = int(raw_input())
	nums = []
	for i in xrange(size * 2 - 1):
		input_numbers = [int(s) for s in raw_input().split(" ")]
		for n in input_numbers:
			if n in nums:
				nums.remove(n)
			else:
				nums.append(n)
	nums.sort()
	out = ' '.join(map(str,nums))
	print "Case #{}: {}".format(case_number, out)

t = int(raw_input())  # read a line with a single integer
for case in xrange(1, t + 1):
	solve(case)
'''
python solution.py <small.in> small.out
python solution.py <large.in> large.out
'''