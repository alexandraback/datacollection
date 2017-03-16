import itertools
fileprefix = 'c-small-3'
reader = open(fileprefix+'.in', 'r')
writer = open(fileprefix+'.out', 'w')
num_cases = int(reader.readline())
for input_number in xrange(1, num_cases+1):
	vals = [int(num) for num in reader.readline().split()]
	N = vals[0]
	esses = vals[1:]
	possible_values = {}
	done = 0
	output = ''
	for num in xrange(1, N+1):
		if done:
			break
		for a_set in itertools.combinations(esses, num):
			total = sum(a_set)
			if(possible_values.has_key(total)):
				first_line = ''
				for a_val in possible_values[total]:
					first_line += str(a_val)+' '
				first_line = first_line[:-1]
				second_line = ''
				for a_val in a_set:
					second_line += str(a_val)+' '
				second_line = second_line[:-1]
				output = output + first_line + '\n' + second_line
				done = 1
				break;
			possible_values[total] = a_set
	if not done:
		writer.write('Case #'+str(input_number)+":\n"+'Impossible'+'\n')
	else:
		writer.write('Case #'+str(input_number)+":\n"+str(output)+'\n')
	
