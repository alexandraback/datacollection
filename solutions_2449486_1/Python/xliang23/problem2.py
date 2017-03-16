import sys
import linecache


# get all lines into a list of integers, shove them into a dictionary
dict_lines = {}
i = 0
fname = open(sys.argv[1], "r")
for line in fname:
	i += 1
	key_name = "row_" + str(i)
	value_list = [int(x) for x in line.split()]
	dict_lines[key_name] = value_list
fname.close()

			
# Let's start checking out the data now ;)
start_line = 2
for t in range(0, int(linecache.getline(sys.argv[1], 1))):

	# we start on line 2:
	crap = "row_" + str(start_line)
	int_rows = dict_lines[crap][0]
	int_cols = dict_lines[crap][1]
		
	list_all_rows = []
	
	for i in range(0, int_rows):
		crap = "row_" + str(start_line + i + 1)
		# get all rows
		list_all_rows.append(dict_lines[crap])
	
	list_all_cols = []
	
	for i in range(0, int_cols):
		# get all cols
		col_list = []
		for j in range(0, int_rows):
			crap = "row_" + str(start_line + j + 1)
			col_list.append(dict_lines[crap][i])
		list_all_cols.append(col_list)

	# get a set of all heights required
	heights_req = []
	for list in list_all_cols:
		for integer in list:
			if integer not in heights_req:
				heights_req.append(integer)
	
	heights_req = sorted(heights_req, reverse = True)
	pass_list = []
	
	for height in heights_req:
		
		height_passed = True
		rows_passed = []
		cols_passed = []
		row_count = 0
		col_count = 0
		
		for row_height in list_all_rows:
			row_count += 1
			if height in row_height:
				pass_row = True
				for height2 in row_height:
					if height < height2:
						pass_row = False
				if pass_row == True:
					rows_passed.append(row_count)
				
		for col_height in list_all_cols:
			col_count += 1
			if height in col_height:
				pass_col = True
				for height2 in col_height:
					if height < height2:
						pass_col = False
				if pass_col == True:
					cols_passed.append(col_count)
				
		# now we know all row and col #'s that have passed for this height
		# check all heights are in a row or col that has passed
		row_index = 0
		for row_height in list_all_rows:
			row_index += 1
			col_index = 0
			for height3 in row_height:
				col_index += 1
				if height == height3:
					if col_index not in cols_passed and row_index not in rows_passed:
						height_passed = False
		pass_list.append(height_passed)

	# now print it
	
	if False in pass_list:
		print "Case #%d: NO" % (t+1)
	else:
		print "Case #%d: YES" % (t+1)
	
	
	start_line += int_rows + 1