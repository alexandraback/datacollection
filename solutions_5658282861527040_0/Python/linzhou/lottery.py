
linearray = []

fp = open('B-small-attempt0.in','r')
for line in fp:
	linearray.append(line.rstrip('\n'))
fp.close()

T = int(linearray[0])
op = open('output.txt','w')
for i in range(0,T):
	splits = linearray[i+1].split()
	
	A = int(splits[0])
	B = int(splits[1])
	K = int(splits[2])
	t = 0
	for x in range(0,A):
		for y in range(0,B):
			z = x & y
			if (z <K):
				t += 1
	op.write("Case #%s: %s\n" % (i+1,t))
op.close()