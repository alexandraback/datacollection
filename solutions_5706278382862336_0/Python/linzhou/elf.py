def mostcommon(a,b):
	if (b == 0):
		return a
	return mostcommon(b,a%b)
linearray = []

fp = open('A-small-attempt0.in','r')
for line in fp:
	linearray.append(line.rstrip('\n'))
fp.close()

T = int(linearray[0])
op = open('output.txt','w')
for i in range(0,T):
	splits = linearray[i+1].split('/')
	P = int(splits[0])
	Q = int(splits[1])

	mc = mostcommon(Q,P)
	P = P/mc
	Q = Q/mc

	tq = Q
	while (tq % 2 == 0):
		tq = tq/2
	if tq == 1:
		ans = 0
		while (Q % 2 == 0):
			Q = Q/2
			ans += 1
			if (Q<P):
				break
			
		op.write("Case #%s: %s\n" % (i+1,ans))
	else:
		op.write("Case #%s: impossible\n" % (i+1))
op.close()
