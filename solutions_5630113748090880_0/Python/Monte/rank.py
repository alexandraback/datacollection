#Rank and File
numLines = int(raw_input())

for line in range(numLines):
	N = int(raw_input())
	arr = []
	mp = {}
	for i in range(2*N-1):
		temp = [int(x) for x in raw_input().split(' ')]
		arr += temp
	ans = []
	for n in arr:
		if n in mp:
			mp[n] += 1
		else:
			mp[n] = 1

	for k in mp:
		if mp[k]%2 == 1:
			ans.append(k)

	ans.sort()
	s= ' '.join([str(x) for x in ans])
	print "Case #{0}: {1}".format((line+1),s)
