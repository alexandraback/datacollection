import string
import fileinput
import copy

f_in = open('A-small-attempt0.in', 'r')
f_out = open('A-small-attempt0.out', 'w')
num_cases = int(f_in.readline())
prob_num = 0
while True:
	if prob_num == num_cases:
		break

	prob_num += 1
	all_nums_in = f_in.readline().strip().split(' ')
	N = all_nums_in[0]
	s_i = all_nums_in[1:]
	s_i = [int(s) for s in s_i]
	
	X = sum(s_i)
	sorted_si = sorted(s_i)

	final_answer = ''
	for s in s_i:
		percent_accounted_for = 0
		num_equal = 0
		percent_needed = 0
		for sorted_s in sorted_si:
			if s > sorted_s:
				percent_accounted_for += (s - sorted_s) / float(X)
				num_equal += 1
			elif s == sorted_s:
				num_equal += 1
			else: # s < sorted_s
				percent_to_add = (sorted_s - s) / float(X)
				if percent_to_add * num_equal + percent_accounted_for > 1.0:
					percent_needed += (1 - percent_accounted_for) / float(num_equal)
					percent_accounted_for = 1
				else:
					percent_needed += percent_to_add
					percent_accounted_for += num_equal * percent_to_add
					num_equal += 1
					s = sorted_s
			if percent_accounted_for >=  1.0:
				break
		if percent_accounted_for < 1:
			percent_needed += (1 - percent_accounted_for) / float(num_equal)


		answer = 100*percent_needed
		final_answer += ('%.6f' % answer) + ' '
		
	final_answer = final_answer.strip()
		
	f_out.write('Case #'+str(prob_num)+': ')
	f_out.write(str(final_answer))
	f_out.write('\n')