def do_recycled(input_file, output_file):
	fout = open(output_file, 'w')
	fin = open(input_file, 'r')
	count_line = fin.readline()
	count_line = count_line.strip()
	line_count = int(count_line)
	for lnum in range(line_count):
		dataline = fin.readline()
		dataline = dataline.strip()
		splitline = dataline.split(' ')
		str_a = splitline[0]
		num_a = int(str_a)
		str_b = splitline[1]
		num_b = int(str_b)
		digits = len(str_a)
		counter = 0
		for num_x in range(num_a, num_b + 1):
			str_x = str(num_x)
			already_seen = dict()
			for cyccount in range(digits - 1):
				str_x = str_x[1:] + str_x[0]
				if str_x not in already_seen:
					already_seen[str_x] = True
					num_cycled = int(str_x)
					if num_cycled > num_x:
						if num_cycled <= num_b:
							counter = counter + 1
		casenum = lnum + 1
		fout.write('Case #' + str(casenum) + ': ' + str(counter))
		fout.write("\n")
	fin.close()
	fout.close()

def main():
	runname = 'C-large'
	input_file = runname + '.in'
	output_file = runname + '.out'
	do_recycled(input_file, output_file)

main()
