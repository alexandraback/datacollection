f = open("b-small-attempt0.in", "r")
new_file = open("bsmallSol", "w")
t = int(f.readline())

def slides (b, m):
	number_paths = {1:1,2:1,3:2,4:4}
	paths_left = m
	last_column = []
	if b <= 4:
		max_value = number_paths[b]
	else:
		max_value = 2**(b-2)
	if m > max_value:
		return (False,None)

	for i in range(4,51):
		number_paths[i] = 2**(i-2)

	for i in range(2,51):
		if number_paths[i] >= m:
			largest = i
			break
	current = largest - 1
	print number_paths
	while current > 0:
		print current
		print paths_left
		print "aqui"
		if paths_left >= number_paths[current]:
			paths_left -= number_paths[current]
			last_elem = 1
		else:
			last_elem = 0
		current -= 1
		last_column.append(last_elem)
	return (True,construct_matrix(b,last_column,largest))

def construct_matrix(b,last_column,largest):
	matrix = []
	for i in range(1,b+1):
		current_row = "0"*i + "1"*(b-i-1) 
		if i == b:
			current_row = "0"*(b-1)
		if i >= largest:
			current_row += "0"
		else:
			current_row += str(last_column[-i])
		matrix.append(current_row)
	return matrix


for i in range(1,t+1):
	b, m = [int(x) for x in f.readline().split(" ")]
	valid, resulting_matrix = slides(b,m)
	if valid:
		new_file.write("Case #"+str(i)+ ": "+"POSSIBLE"+"\n")
		for i in resulting_matrix:
			new_file.write(i+"\n")
	else:
		new_file.write("Case #"+str(i)+ ": "+"IMPOSSIBLE"+"\n")