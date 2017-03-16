fi = open("A-large.in")
fo = open("A-large.out", "w")

line = next(fi)
T = int(line)
for t in range(T):
	line = next(fi)
	N = int(line)
	y = "INSOMNIA"
	test = [0 for x in range(10)]
	if N > 0:
		y = 0
		while min(test) == 0:
			y += N
			yy = y
			while yy > 0:
				digit = yy % 10
				test[digit] = 1
				yy = yy // 10

	fo.write("Case #" + str(t+1) + ": " + str(y) + "\n")

fi.close()
fo.close()
