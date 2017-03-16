squared_len = 16

max_num = 10 ** squared_len
max_pal = int(max_num ** 0.5)
pal_list = range(1,10)

square_pals = []
def is_pal(num):
	return str(num) == str(num)[::-1]
	
for num in xrange(1, int((1.0 * max_num) ** 0.25)):
	if num % 10 == 0:
		continue
	for middle_dig in xrange(11):
		for num_zeros in xrange(squared_len / 2):
			pal_half_str = "0" * num_zeros + str(num)
			if middle_dig == 10:
				pal = int(pal_half_str[::-1] + pal_half_str)
			else:
				pal = int(pal_half_str[::-1] + str(middle_dig) + pal_half_str)			
			if pal > max_pal:
				continue
			assert is_pal(pal), str(pal)
			pal_list.append(pal)
		
#pal_list = sorted(pal_list)
#print pal_list
for pal in pal_list:
	squared = pal*pal
	if squared > max_num:
		continue
	if is_pal(squared):
		#print pal, squared
		square_pals.append(squared)
		
square_pals = sorted(square_pals)
	

			
		

import os

#input = r"B-large.in"
#input = r"testinput.txt"
input = r"C-large-1.in"
output = r"output2.txt"
#output = r"testoutput.txt"

def get_solution_str(min,max):
	#print min,max, square_pals
	num_vals = 0
	for i in square_pals:
		#print i, min ,max
		if i >= min and i <=max:
			#print "shit"
			num_vals+=1
	return str(num_vals)
	
lines = open(input, "r").readlines()
num_cases = int(lines[0])

out = open(output, "w")

cur_case = 1
for line_index, line in enumerate(lines[1:]):
	min, max = map(int, line[:-1].split(" "))
	out.write("Case #" + str(line_index + 1) + ": " + get_solution_str(min,max) + "\n")