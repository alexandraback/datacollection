fin = open("in.txt", "r")
fout = open("out.txt", "w")
lineCount = int(fin.readline())

for x in xrange(lineCount):
	vals = fin.readline().strip().split(" ")
	k = int(vals[0])
	c = int(vals[1])
	s = int(vals[2])
	
	covered = 0
	result = ""
	while s>0 and covered<k:
		pos = covered
		posTotal = pos
		covered += 1
		for y in xrange(1, c):
			if covered < k:
				pos += 1
				covered += 1
			posTotal = posTotal * k + pos
		result += " %d" % (posTotal+1)
		s -= 1
	
	if covered < k: 
		fout.write("Case #%d: IMPOSSIBLE\n" % x+1)
	else:
		fout.write("Case #%d:%s\n" % (x+1, result))
		
fin.close()
fout.close()