import sys
import string

num_case = int(sys.stdin.readline())

for cur_case in range(1, num_case+1):
	pair_list = []
	[low, high] = map(int, sys.stdin.readline().split(' '))
	
	for i in range(low,high+1):
		if i > 9:
			cyc_list = list(str(i))
			# iterate through all possible cycled number
			for j in range(1, len(cyc_list)):
				last_item = cyc_list.pop()
				cyc_list.insert(0, last_item)
				if last_item == 0:
					continue
				new_num = int(''.join(cyc_list))
				if new_num > i and new_num <= high:
					pair_list.append((i,new_num))
	
	# Get rid of the redundency
	pair_list = list(set(pair_list))
	
	# print out final result
	file = open('output.txt', 'a')
	file.write('Case #%d: %d\n'%(cur_case, len(pair_list)))