fin = open("in.txt", "r")
fout = open("out.txt", "w")
total = int(fin.readline())

for x in xrange(total):
	used = [False, False, False, False, False, False, False, False, False, False]
	usedCount = 0

	nr = int(fin.readline())
	for y in xrange(1,100):
		curNr = nr * y
		while curNr > 0:
			digit = curNr % 10
			curNr = int(curNr / 10)
			if not used[digit]:
				used[digit] = True
				usedCount += 1
		if usedCount == 10:
			fout.write("Case #%d: %d\n" % (x+1, nr * y))
			break
	if usedCount != 10:
		fout.write("Case #%d: INSOMNIA\n" % (x+1))


fin.close()
fout.close()