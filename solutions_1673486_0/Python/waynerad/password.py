def do_password(input_file, output_file):
	fout = open(output_file, 'w')
	fin = open(input_file, 'r')
	count_line = fin.readline()
	count_line = count_line.strip()
	line_count = int(count_line)
	for lnum in range(line_count):
		dataline = fin.readline()
		dataline = dataline.strip()
		casenum = lnum + 1
		fout.write('Case #' + str(casenum) + ': ')
		splitline = dataline.split(' ')
		sofar = splitline[0]
		sofar = int(sofar)
		total = splitline[1]
		total = int(total)
		dataline = fin.readline()
		dataline = dataline.strip()
		splitline = dataline.split(' ')
		probs = []
		for idx in range(sofar):
			pv = splitline[idx]
			pv = float(pv)
			probs.append(pv)
		minz = total + 2
		for idx in range(sofar + 1):
			to_type_if_success = (idx * 2) + total - sofar + 1
			to_type_if_fail = (idx * 2) + total - sofar + 1 + total + 1
			if idx == sofar:
				odds_correct = 1.0
			else:
				odds_correct = 1.0
				for ij in range(sofar - idx):
					odds_correct = odds_correct * probs[ij]
			odds_wrong = 1 - odds_correct
			expected_val = (odds_correct * to_type_if_success) + (odds_wrong * to_type_if_fail)
			if expected_val < minz:
				minz = expected_val
		fout.write(str(minz))
		fout.write("\n")
	fin.close()
	fout.close()

def main():
	runname = 'A-small-attempt0'
	input_file = runname + '.in'
	output_file = runname + '.out'
	do_password(input_file, output_file)

main()
