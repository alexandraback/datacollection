import sys

num_case = int(sys.stdin.readline())

for cur_case in range(1, num_case+1):
	count_valid = 0
	input = map(int, sys.stdin.readline().split(' '))
	num_googler = input[0]
	num_suprise = input[1]
	best_score = input[2]
	# define the threshold for normal and suprising
	upper_th = max(best_score*3-2, 0)
	lower_th = best_score*3-4
	if lower_th < 0:
		lower_th = 31
	
	for sum in input[3:]:
		if sum >= upper_th:
			count_valid = count_valid + 1
		elif sum >= lower_th and num_suprise > 0:
			count_valid = count_valid + 1
			num_suprise = num_suprise - 1
			
	# print out final result
	file = open('output.txt', 'a')
	# Uniqueness of the result
	file.write('Case #%d: %d\n'%(cur_case, count_valid))