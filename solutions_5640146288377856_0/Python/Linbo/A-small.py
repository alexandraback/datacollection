with open("A-small-attempt0.in",'r') as f:
	out =""
	T = int(f.readline())
	for i in xrange(T):
		data = f.readline().split()
		R = int(data[0])
		C = int(data[1])
		W = int(data[2])

		if (C==W or W ==1):
			score = C
		elif C%W ==0:
			score = C/W + W - 1
		else:
			score = C/W + W

		out += "case #%d: %d \n" % (i+1,score)

with open("A-small-attempt0.out", 'aw') as f2:
    f2.write(out)





			
