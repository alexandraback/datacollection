with open("A-large.in",'r') as f:
	out =""
	T = int(f.readline())
	for i in xrange(T):
		data = f.readline().split()
		R = int(data[0])
		C = int(data[1])
		W = int(data[2])

		if W ==1:
			score = R*C
		if C==W:
			score = R+W-1
		elif C%W ==0:
			score = (R-1)*(C/W)+C/W + W - 1
		else:
			score = (R-1)*(C/W) + C/W + W

		out += "case #%d: %d \n" % (i+1,score)

with open("A-large.out", 'aw') as f2:
    f2.write(out)





			
