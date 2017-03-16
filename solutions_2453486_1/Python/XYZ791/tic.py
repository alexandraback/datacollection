
def processCase(data):
	# do some counting
	rows_x = [0,0,0,0]
	cols_x = [0,0,0,0]
	rows_o = [0,0,0,0]
	cols_o = [0,0,0,0]
	
	incomplete = False
	
	for row in range(4):
		for col in range(4):
			value = data[row][col]
			if value == 'X':
				rows_x[row] = rows_x[row] + 1
				cols_x[col] = cols_x[col] + 1
			elif value == 'O':
				rows_o[row] = rows_o[row] + 1
				cols_o[col] = cols_o[col] + 1
			elif value == 'T':
				rows_x[row] = rows_x[row] + 1
				cols_x[col] = cols_x[col] + 1
				rows_o[row] = rows_o[row] + 1
				cols_o[col] = cols_o[col] + 1
			elif value == '.':
				incomplete = True
		
		# check current row
		if rows_x[row] >= 4:
			return "X won"
		elif rows_o[row] >= 4:
			return "O won"
	
	# check cols
	for col in range(4):
		if cols_x[col] >= 4:
			return "X won"
		elif cols_o[col] >= 4:
			return "O won"
	
	# check leading diagonal
	diag1_x = 0
	diag1_o = 0
	for counter in range(4):
		value = data[counter][counter]
		if value == 'X':
			diag1_x = diag1_x + 1
		elif value == 'O':
			diag1_o = diag1_o + 1
		elif value == 'T':
			diag1_x = diag1_x + 1
			diag1_o = diag1_o + 1
	if diag1_x >= 4:
		return "X won"
	elif diag1_o >= 4:
		return "O won"
	
	# check other diagonal
	diag2_x = 0
	diag2_o = 0
	for counter in range(4):
		value = data[counter][3-counter]
		if value == 'X':
			diag2_x = diag2_x + 1
		elif value == 'O':
			diag2_o = diag2_o + 1
		elif value == 'T':
			diag2_x = diag2_x + 1
			diag2_o = diag2_o + 1
	if diag2_x >= 4:
		return "X won"
	elif diag2_o >= 4:
		return "O won"
	
	if incomplete:
		return "Game has not completed"
	else:
		return "Draw"

# open input file
in_file = open("in", "r")
n_cases = int(in_file.readline())

# open output file
out_file = open("out", "w")

# read then process test cases
for test_case in range(n_cases):
	case = []
	for line in range(4):
		case.append(in_file.readline())
	in_file.readline()
	
	out_file.write("Case #{}: {}\n".format(test_case+1, processCase(case)))

in_file.close()
out_file.close()
