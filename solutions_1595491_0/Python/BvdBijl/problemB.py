f = open('B-small-attempt0.in')
output = open('ResultB.out', 'w')

cases = int(f.readline())

for i in xrange(1, cases + 1):
	nums = map(int, f.readline().split())
	
	N = nums[0]
	S = nums[1]
	p = nums[2]
	t = nums[3:]
	
	total = 0
	
	for employee in t:
		if employee < p:
			continue
		if (employee + 2) / 3 >= p:
			total += 1
		elif S > 0 and (employee + 4) / 3 >= p:
			S -= 1
			total += 1
	
	
	output.write('Case #' + str(i) + ': ' + str(total) + '\n')
f.close()