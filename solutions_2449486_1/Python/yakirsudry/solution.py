import os

input = r"B-large.in"
#output = r"output1.txt"
output = r"output2.txt"

def get_solution_str(table):	
	max_rows = [max(row) for row in table]
	max_cols = [""] * len(table[0])
	for col in xrange(len(table[0])):
		max_cols[col] = max([row[col] for row in table])
		
	for row, row_data in enumerate(table):
		for col, hei in enumerate(row_data):
			if hei == 100:
				continue
			if hei < max_cols[col] and hei < max_rows[row]:
				return "NO"
	return "YES"
		
	
	
				
lines = open(input, "r").readlines()
num_cases = int(lines[0])

out = open(output, "w")
cur_line = 1
cur_case = 1
for i in xrange(num_cases):
	rows_cols = lines[cur_line]
	splitted_line = rows_cols.split(" ")
	rows=int(splitted_line[0])
	cols=int(splitted_line[1])
	table = [""] * rows
	cur_line +=1
	for i in xrange(rows):
		row = lines[cur_line]
		row_nums = [int(j) for j in row.split(" ")]
		cur_line +=1
		table[i] = row_nums
	#print table
	out.write("Case #%d: %s\n" %(cur_case, get_solution_str(table)))
	cur_case += 1
	#print table