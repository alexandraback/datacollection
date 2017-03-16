def do_dancing(input_file, output_file):
	fout = open(output_file, 'w')
	fin = open(input_file, 'r')
	count_line = fin.readline()
	count_line = count_line.strip()
	line_count = int(count_line)
	for lnum in range(line_count):
		dataline = fin.readline()
		dataline = dataline.strip()
		datasplit = dataline.split()
		num_googlers = datasplit[0]
		num_googlers = int(num_googlers)
		num_surprising = datasplit[1]
		num_surprising = int(num_surprising)
		threshold_p = datasplit[2]
		threshold_p = int(threshold_p)
		overcount = 0
		spillist = []
		for i in range(3, len(datasplit)):
			total_points = datasplit[i]
			total_points = int(total_points)
			dvr = divmod(total_points, 3)
			best = dvr[0]
			if dvr[1] != 0:
				best = best + 1
			if best >= threshold_p:
				overcount = overcount + 1
			else:
				spillist.append(total_points)
		for total_points in spillist:
			if num_surprising > 0:
				dvr = divmod(total_points, 3)
				best = dvr[0]
				if dvr[1] != 0:
					best = best + 1
				if (dvr[0] == 0) and (dvr[1] != 2):
					# can't do it! need to drop too low!
					a = 5
				else:
					if best != 10:
						if (dvr[1] == 0) or (dvr[1] == 2):
							best = best + 1
							if best >= threshold_p:
								overcount = overcount + 1
								num_surprising = num_surprising - 1
		casenum = lnum + 1
		fout.write('Case #' + str(casenum) + ': ' + str(overcount))
		fout.write("\n")
	fin.close()
	fout.close()

def main():
	runname = 'B-large'
	input_file = runname + '.in'
	output_file = runname + '.out'
	do_dancing(input_file, output_file)

main()

# 24	8 + 8 + 8	7 + 8 + 9	8R0	DROP!
# 25	8 + 8 + 9	7 + 9 + 9	8R1	DROP!
# 6	8 + 9 + 9	8 + 8 + 10	8R2


