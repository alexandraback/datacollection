def str_check(vec):
	if vec.count(".") > 0:
		return [False,"N"]
	t = False
	if vec.count("T") == 1:
		t = True
	x = vec.count("X")
	if x == 4 or (x == 3 and t):
		return [True,"X"]
	o = vec.count("O")
	if o == 4 or (o == 3 and t):
		return [True,"O"]
	return [False,"D"]

def arr_check(mlist):
	n = "D"
	# check columns
	for i in range(0,4):
		vec = str_check(mlist[i])
		if vec[0]:
			return vec[1]
		elif vec[1] == "N":
			n = "N"
	# check rows
	for i in range(0,4):
		test = []
		for j in range(0,4):
			test.append(mlist[j][i])
		vec = str_check(test)
		if vec[0]:
			return vec[1]
		elif vec[1] == "N":
			n = "N"
	vec = str_check([mlist[0][0],mlist[1][1],mlist[2][2],mlist[3][3]])
	if vec[0]:
		return vec[1]
	elif vec[1] == "N":
		n = "N"
	vec = str_check([mlist[0][3],mlist[1][2],mlist[2][1],mlist[3][0]])
	if vec[0]:
		return vec[1]
	elif vec[1] == "N":
		n = "N"
	return n


inp = open("file1.txt").read().splitlines()
outp = open("out1.txt","w")

i = 0
c = 1
while c-1 < int(inp[0]):
	curr_arr = []
	for j in range(0,4):
		i += 1
		curr_arr.append(list(inp[i]))
	s = arr_check(curr_arr)
	if s == "X":
		outp.write("Case #"+str(c)+": X won\n")
	elif s == "O":
		outp.write("Case #"+str(c)+": O won\n")
	elif s == "N":
		outp.write("Case #"+str(c)+": Game has not completed\n")
	else:
		outp.write("Case #"+str(c)+": Draw\n")
	c += 1
	i += 1					# newline
