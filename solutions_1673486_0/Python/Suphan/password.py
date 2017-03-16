input = open('A-small-attempt0.in')
output = open('A-small-attempt0.out', 'w')
num_of_lines = int(input.readline())
num = 0
while num < num_of_lines:
	parts = input.readline().split()
	A = int(parts[0])
	B = int(parts[1])
	parts = input.readline().split()
	pi = []
	for p in parts:
		pi.append(float(p))
	
	min_stroke = 10000000
	cul_prob = 1.0
	for i in xrange(A + 1):
		stroke = (A - i) + (B - i) + 1
		avg_stroke = stroke * cul_prob
		stroke += B + 1
		avg_stroke += stroke * (1.0 - cul_prob)
		
		if avg_stroke < min_stroke:
			min_stroke = avg_stroke
		
		if i < A:
			cul_prob *= pi[i]
	
	stroke = B + 2
	if stroke < min_stroke:
		min_stroke = stroke
	
	output.write('Case #' + str(num + 1) + ': ' + str(min_stroke) + '\n')

	num += 1
output.close()
