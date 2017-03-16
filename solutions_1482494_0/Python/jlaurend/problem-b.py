import string
import fileinput

f_in = open('B-small-attempt1.in', 'r')
f_out = open('B-small-attempt1.out', 'w')
#lines = f_in.readlines()
num_cases = int(f_in.readline())
prob_num = 0
while prob_num < num_cases:
	prob_num += 1
	num_levels = int(f_in.readline())
	level_vals = []
	for i in range(num_levels):
		vals = f_in.readline().strip().split(' ')
		level_vals.append((int(vals[0]), int(vals[1]), False))
		
#	vals_in_1order = sorted(level_vals, key=lambda blah: blah[0])
	vals_in_2order = sorted(level_vals, key=lambda blah: blah[1])
	vals_in_reverse_2order = sorted(level_vals, key=lambda blah: blah[1], reverse=True)
	
	num_levels_done = 0
	num_turns = 0
	num_stars = 0
	while num_levels_done < num_levels:
		# if you can 2-star one, do it
		if num_stars >= vals_in_2order[0][1]:
			if vals_in_2order[0][2]: 
				num_stars += 1
			else:
				num_stars += 2
			del vals_in_2order[0]
			del vals_in_reverse_2order[-1]
			num_levels_done += 1
		else: 
			valid_solution = False
			for i in range(len(vals_in_reverse_2order)):
				val = vals_in_reverse_2order[i]
				if num_stars >= val[0]:
					num_stars += 1
					valid_solution = True
					vals_in_reverse_2order[i] = (val[0], val[1], True)
					vals_in_2order[len(vals_in_2order)-i-1] = (val[0], val[1], True)
					break
			
			if not valid_solution:
				num_turns = "Too Bad"
				break
				
		num_turns += 1
		

		

	f_out.write('Case #'+str(prob_num)+': ')
	f_out.write(str(num_turns))
	f_out.write('\n')