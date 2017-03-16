print("Case #1: ")
for i in range(1,51):
	x = bin(i)
	x = x[2:]
	y = len(x)
	for i in range(6-y):
		x = "0" + x
	z = ""
	for i in range(6):
		z += x[i]
		z += x[i]
	z = "11" + z + "11" + " 3 4 5 6 7 8 9 10 11"
	print(z)