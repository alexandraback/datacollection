fin = open("a.in", "r")
fout = open("a.out", "w")

t = int(fin.readline())
for i in xrange(1, t+1):
	print i
	n = int(fin.readline())
	plus = n
	fout.write("Case #" + str(i) + ": ")
	if n == 0:
		fout.write("INSOMNIA\n")
		continue
	seen = [0]*10
	sc = 0
	for j in xrange(1, 10**8):
		string = str(n)
		for char in string:
			digit = int(char)
			if not seen[digit]:
				seen[digit] = 1
				sc += 1
		if sc == 10:
			break
		n += plus
	if sc == 10:
		fout.write(str(n) + "\n")
	else:
		fout.write("INSOMNIA\n")