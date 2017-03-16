import itertools

fd = open("in1", "r")

lines = fd.readlines()

testcases = int(lines[0])



fout = open("out1", "w")

for line_ind in xrange(1,len(lines)):
	line  = lines[line_ind]

	fout.write("Case #" + str(line_ind) + ": ")



	iteration = itertools.count()

	next(iteration)
	flag = False
	start_number = int(line)
	seen_dict = {}
	digits = []
	n = 0
	for i in iteration:
		number = start_number * i
		# Debug
		#print i
		curr_digits = map(int, str(number))
		#print curr_digits


		for d in curr_digits:
			if (d not in digits):
				digits.append(d)
				n += 1
			if (n == 10):
				fout.write(str(number) + "\n")
				flag = True
				break
		if(flag):
			break
		if (number not in seen_dict):
			seen_dict[number] = 1
		else:
			fout.write("INSOMNIA\n")
			flag = True
			break
		if(flag):
			break
