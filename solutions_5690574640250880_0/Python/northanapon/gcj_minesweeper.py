import copy
f = open("C-small-attempt4.in", "r")
f2=open("C-small-attempt4.out", "w")
#f = open("text.txt", "r")
#f2=open("text.out.txt", "w")

def fill_row(row, M, field):
	count = 0
	for i in range(len(field[row])):
		if field[row][i] != '*':
			count += 1
	if count  <= M:
		for i in range(len(field[row])):
                	if field[row][i] != '*':
               		       	field[row][i] = '*'
	else: return 0
	return count

def fill_top_rows(row_offset, num_rows, M, field):
	left = M
	count = 0
	for i in range(num_rows):
		count += fill_row(i+row_offset, left, field)
		left = M - count
		if left == 0: break
	return count

def fill_bot_rows(row_offset, num_rows, M, field):
	left = M
	count = 0
	for i in range(num_rows):
		count += fill_row(row_offset-i, left, field)
		left = M - count
		if left == 0: break
	return count

def fill_column(col, M, field):
	count = 0
	for i in range(len(field)):
                if field[i][col] != '*':
                        count += 1
	if count <= M:
		for i in range(len(field)):
			if field[i][col] != '*':
				field[i][col] = '*'
	else: return 0
	return count

def fill_left_columns(col_offset, num_cols, M, field):
	left = M
	count = 0
	for i in range(num_cols):
		count += fill_column(i+col_offset, left, field)
		left = M - count
		if left == 0: break
	return count


def fill_right_columns(col_offset, num_cols, M, field):
	left = M
	count = 0
	for i in range(num_cols):
		count += fill_column(col_offset-i, left, field)
		left = M - count
		if left == 0: break
	return count

def make_field(R, C):
	return [['.' for i in range(C)] for j in range(R)]

def str_field(field):
	a = []
	for row in field:
		for x in row :
			a.append(x)
		a.append('\n')
	str_rep = ''.join(a)
	return str_rep.strip()

def count(field, row, col):
	if row >= len(field) or row < 0:
		return 0
	if col >= len(field[0]) or col < 0:
		return 0
	if field[row][col] == '*':
		return 1
	return 0

def click(field, x, row, col):
	if row >= len(field) or row < 0:
		return
	if col >= len(field[0]) or col < 0:
		return
	if field[row][col] == '*':
		return
	if x[row][col] != '.':# and x[row][col] != 'x':
		return
	c = 0
	c += count(field, row-1, col-1)
	c += count(field, row-1, col)
	c += count(field, row-1, col+1)
	c += count(field, row, col-1)
	c += count(field, row, col+1)
	c += count(field, row+1, col-1)
	c += count(field, row+1, col)
	c += count(field, row+1, col+1)

	x[row][col] = str(c)
	if c == 0:
		click(field, x, row-1, col-1)
		click(field, x, row-1, col)
		click(field, x, row-1, col+1)
		click(field, x, row, col-1)
		click(field, x, row, col+1)
		click(field, x, row+1, col-1)
		click(field, x, row+1, col)
		click(field, x, row+1, col+1)

def dot_exist(field):
	for row in range(len(field)):
		for col in range(len(field[0])):
			if field[row][col] == '.':# or field[row][col] == 'x':
				return True
	return False

def check(field, mark=False):
	for row in range(len(field)):
		for col in range(len(field[0])):
			if field[row][col] == '*':
				continue
			x = copy.deepcopy(field)
			click(field, x, row, col)
			if not dot_exist(x):
				if mark: field[row][col] = 'c'
				return True
	return False

def _dfs(field, M, R, C, n):
	r = n/C
	c = n -r
	#if not check(field) : return None
	if M <= 0 :
		#print str_field(field)
		if not check(field) : return None 
		return field
	for row in range(r, len(field)):
		for col in range(c, len(field[0])):
			if field[row][col] == '*':
				continue
			local_f = copy.deepcopy(field)
			local_f[row][col] = '*'
			res = dfs(local_f, M-1, R, C, n+1)
			if res is not None: return res

def dfs(field, M, R, C, n):
        if M <= 0 :
                if not check(field) : return None
                return field
        for i in range(n, (R*C)-1):
		row = i/C
		col = i - row*C
		if field[row][col] == '*':
                	continue
                local_f = copy.deepcopy(field)
                local_f[row][col] = '*'
                res = dfs(local_f, M-1, R, C, i+1)
               	if res is not None: return res

num_cases = int(f.readline().strip())

for i in range(num_cases):
	f2.write("Case #" + str(i+1)+":\n")
	p = f.readline().strip().split(' ')
	R = int(p[0])
	C = int(p[1])
	M = int(p[2])
	field = make_field(R, C)
	used = 0
	left = M
	if R >= 4:
		used += fill_top_rows(0, R/2-2, left, field)
		left = M - used
		used += fill_bot_rows(R-1, R/2-2, left, field)
		left = M - used
		if R % 2 != 0:# or R == 4:
			used += fill_bot_rows(R-1-R/2-2, 1, left, field)
        	       	left = M - used
	#print str_field(field)
	if C >= 4:
		used += fill_left_columns(0, C/2-2, left, field)
		left = M - used
		used += fill_right_columns(C-1, C/2-2, left, field)
		left = M - used
		if C % 2 != 0:# or C == 4 :
			used += fill_right_columns(C-1-C/2-2, 1, left, field)
	                left = M - used

	#print str_field(field)
	#print left
	a = dfs(field, left, R, C, 0)
	if a is not None:
		check(a, mark=True)
		f2.write(str_field(a)+"\n")
	else:
		#print "Case #" + str(i+1)+":"
		#print p
		#print str_field(field)
		#print left
		f2.write("Impossible\n")
f.close()
f2.close()	


	

