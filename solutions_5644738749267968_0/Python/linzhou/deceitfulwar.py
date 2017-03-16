def findindex(arr,value):
	l = 0
	h = len(arr)-1
	m = (l+h)/2
	while (l<h):
		if (arr[m]>value):
			h = m
			m = (l+h)/2
		else:
			l = m+1
			m = (l+h)/2
	if (l>h):
		return h+1
	else:
		if (arr[h] > value):
			return h
		else:
			return h+1

linearray = []

fp = open('D-small-attempt0.in','r')
for line in fp:
	linearray.append(line.rstrip('\n'))
fp.close()

T = int(linearray[0])
op = open('fourth.out','w')
for i in range(0,T):
	n = int(linearray[3*i+1])
	naomi = []
	ken = []
	
	sn = linearray[3*i+2].split()
	sk = linearray[3*i+3].split()
	for j in range(0,n):
		naomi.append(float(sn[j]))
		ken.append(float(sk[j]))
	
	
	naomi.sort()
	ken.sort()
	kent = list(ken)

	w = 0
	for v in naomi:
		ki = findindex(ken,v)
		if (ki>=len(ken)):
			ki = 0
			w += 1
		kv = ken.pop(ki)
	

	wt = 0
	for v in naomi:
		if (v > kent[0]):
			ki = findindex(kent,kent[len(kent)-1] + 0.000001)
		else:
			ki = findindex(kent,kent[len(kent)-1] - 0.000001)
		if (ki >= len(kent)):
			ki = 0
			wt += 1
		kent.pop(ki)
	op.write("Case #%s: %s %s\n" % (i+1,wt,w))
op.close()