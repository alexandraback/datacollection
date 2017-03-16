linearray = []

fp = open('./B-large.in','r')
for line in fp:
	linearray.append(line.rstrip('\n'))
fp.close()

op = open('./second.out','w')
T = int(linearray[0])
for i in range(0,T):
	line = linearray[i+1]
	splits = line.split()
	C = float(splits[0])
	F = float(splits[1])
	X = float(splits[2])
	cur = 2.0
	used = 0
	while True:
		if (X/cur > (C/cur + X/(cur+F))):
			used = used + C/cur
			cur = cur + F
		else:
			used = used + X/cur
			break
	op.write("Case #%s: %.7f\n" % (i+1,used))
op.close()