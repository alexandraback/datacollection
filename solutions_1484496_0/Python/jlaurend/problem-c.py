import string
import fileinput
import copy
import itertools

f_in = open('C-small-attempt1.in', 'r')
f_out = open('C-small-attempt1.out', 'w')
num_cases = int(f_in.readline())
prob_num = 0
while True:
	if prob_num == num_cases:
		break
	prob_num += 1

	answer = ''
	nums = f_in.readline().strip().split(' ')
	N = int(nums[0])
	nums = nums[1:]
	nums = [int(n) for n in nums]

	success_set_1 = None
	success_set_2 = None
	break_out = False
	for i in range(N):
		sets1 = itertools.combinations(nums, i)
		if break_out:
			break
		for set1 in sets1:
			if break_out:
				break
			for j in range(N):
				if break_out:
					break
				sets2 = itertools.combinations(nums, j)
				sum_set1 = sum(set1)
				for set2 in sets2:
					sum_set2 = sum(set2)
					if len(set1) == 0 or len(set2) == 0 or set1 == set2:
						continue
					elif sum_set1 == sum_set2:
						success_set_1 = set1
						success_set_2 = set2
						break_out = True
						break
					elif sum_set2 > sum_set1:
						break
	if success_set_1 == None:
		answer = 'Impossible'
	else:
		for s in success_set_1:
			answer += str(s) + ' '
		answer += '\n'
		for s in success_set_2:
			answer += str(s) + ' '
			

	f_out.write('Case #'+str(prob_num)+':'+'\n')
	f_out.write(str(answer))
	f_out.write('\n')