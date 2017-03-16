T = int(raw_input())
for t in range(1, T+1):
	N = int(raw_input())
	data = [0]*2501
	for i in range(2*N-1):
		l = map(int, raw_input().split())
		for el in l:
			data[el]+=1
	leftlist = []
	for i in range(1, 2501):
		if(data[i]%2==1):
			leftlist.append(i)
	leftlist.sort()
	print "Case #" + str(t) + ":",
	for i in range(N):
		print leftlist[i],
	print ""