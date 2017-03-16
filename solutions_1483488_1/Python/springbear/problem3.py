f = open("C-large.in")
num_testcases = int(f.readline())
inputs = []

for i in range(0, num_testcases):
	inputs.append(f.readline())

for i in range(0, num_testcases):
	inputs[i] = inputs[i].split()
	A = int(inputs[i][0])
	B = int(inputs[i][1])

	count = 0
	for n in range(A, B-1):
		remaining_number = n
		tmp = remaining_number
		output_tmp = []
		number_count = 0

		while tmp > 0:
			tmp = tmp / 10 
			number_count += 1
		
		for j in range(1, number_count):

			upper = remaining_number % (10 ** j) * (10 ** (number_count - j))
			recycle_number = upper + 	remaining_number // (10 ** j)
	
			if recycle_number > A and recycle_number <= B and n < recycle_number and output_tmp.count(recycle_number) == 0:
				count = count + 1
				output_tmp.append(recycle_number)
		
	print "Case #%d:" % (i+1),
	print "%d" % count
