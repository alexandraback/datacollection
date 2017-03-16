#!C:\Python27\python

input = file('B.input', 'r')
output = file('B.output', 'w')

num_cases = int(input.readline())

for i_case in range(1, num_cases+1):
	testcase = input.readline().strip()
	testcase_list = map(int, testcase.split(' '))
	
	num_googlers = testcase_list[0]
	num_surprising = testcase_list[1]
	best_at_least = testcase_list[2]
	scores = testcase_list[3:]
	
	threshold = max((3 * best_at_least) - 2, 0)
	surp_threshold = max(threshold - 2, 0)
	
	print "Threshold: %d, SurpThreshold: %d" % (threshold, surp_threshold)
	first = 0
	second = 0
	
	print scores
	for_scores = list(scores)
	for score in for_scores:
		if score >= threshold and score >= best_at_least:
			first = first + 1
			scores.remove(score)
	print scores
	for_scores = list(scores)
	for score in for_scores:
		if score >= surp_threshold and score >= best_at_least:
			second = second + 1
			scores.remove(score)
	print scores
	
	result = first + min(second, num_surprising)
	o = "Case #%d: %d" % (i_case, result)
	print o
	output.write(o + '\n')