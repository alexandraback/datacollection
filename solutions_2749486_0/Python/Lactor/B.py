
inp = open("B.in", "r")
out = open("B.out", "w")

T = int(inp.readline())

for z in range(T):
	st = inp.readline()
	A = st.split(' ')
	x = int(A[0])
	y = int(A[1])	

	print x,y

	resp = ""

	if x > 0:
		for i in range(x):
			resp+="WE"

	if x < 0:
		for i in range(-x):
			resp+="EW"

	if y > 0:
		for i in range(y):
			resp+="SN"

	if y < 0:
		for i in range(-y):
			resp+="NS"

	print resp

	out.write("Case #" + str(z+1) + ": " + resp + "\n")

