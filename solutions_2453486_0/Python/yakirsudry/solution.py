import os

input = r"A-small-attempt0.in"
output = r"testoutput.txt"

def get_solution_str(table):
	o_wins_string = "O won"
	x_wins_string = "X won"
	draw_string = "Draw"
	not_finished_string = "Game has not completed"
	o_good_chars = ["O","T"]
	x_good_chars = ["X","T"]
	o_wins = False
	x_wins = False
	for i in xrange(4):
		if table[i][0] in o_good_chars and table[i][1] in o_good_chars and table[i][2] in o_good_chars and table[i][3] in o_good_chars:
			return o_wins_string
		if table[i][0] in x_good_chars and table[i][1] in x_good_chars and table[i][2] in x_good_chars and table[i][3] in x_good_chars:
			return x_wins_string
			
		if table[0][i] in o_good_chars and table[1][i] in o_good_chars and table[2][i] in o_good_chars and table[3][i] in o_good_chars:
			return o_wins_string
		if table[0][i] in x_good_chars and table[1][i] in x_good_chars and table[2][i] in x_good_chars and table[3][i] in x_good_chars:
			return x_wins_string
			
	if table[0][0] in o_good_chars and table[1][1] in o_good_chars and table[2][2] in o_good_chars and table[3][3] in o_good_chars:
		return o_wins_string		
	if table[0][0] in x_good_chars and table[1][1] in x_good_chars and table[2][2] in x_good_chars and table[3][3] in x_good_chars:
		return x_wins_string
		
	if table[0][3] in o_good_chars and table[1][2] in o_good_chars and table[2][1] in o_good_chars and table[3][0] in o_good_chars:
		return o_wins_string		
	if table[0][3] in x_good_chars and table[1][2] in x_good_chars and table[2][1] in x_good_chars and table[3][0] in x_good_chars:
		return x_wins_string		
		
	for i in xrange(4):
		if "." in table[i]:
			return not_finished_string
	return draw_string
				

def decode(line):
	return [i for i in line]

lines = open(input, "r").readlines()
num_cases = int(lines[0])

out = open(output, "w")
cur_line = 1
table = [""] * 4
cur_case = 1
for i in xrange(num_cases):
	for i in xrange(4):
		table[i] = decode(lines[cur_line][:-1])
		cur_line += 1
	cur_line += 1
	out.write("Case #%d: %s\n" %(cur_case, get_solution_str(table)))
	cur_case += 1
	print table