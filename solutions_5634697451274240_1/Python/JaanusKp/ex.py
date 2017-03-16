fin = open("in.txt", "r")
fout = open("out.txt", "w")
total = int(fin.readline())

for x in xrange(total):
	line = fin.readline().strip()
	count = 0
	for y in xrange(1,len(line)):
		if line[y-1] != line[y]:
			count += 1
	if line[len(line)-1] == '-':
		count += 1
	fout.write("Case #%d: %d\n" % (x+1, count))

fin.close()
fout.close()