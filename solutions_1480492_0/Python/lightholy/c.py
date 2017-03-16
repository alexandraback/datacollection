testCount = int(raw_input())
for testIndex in range(testCount):
	ans = "Case #" + str(testIndex+1) + ": "
	n = int(raw_input())
	a = []
	for i in range(n):
		dat = raw_input().split(" ")
		a += [(int(dat[1]), int(dat[2]))]
	a.sort(key=lambda x:-x[0] - x[1]*10000)
	crash = set()
	for i in range(n):
		for j in range(i+1, n):
			if a[i][0] < a[j][0] and a[i][1]-a[j][1] > 5:
				crash.add((a[i][1]-a[j][1]-5.0) / (a[j][0] - a[i][0]))
	flag = True
	crash2 = sorted(list(crash))
	#print(crash2)
	for k in crash2:
		pos = [(x[0] * k + x[1], x[0]) for x in a]
		pos.sort(key=lambda x:x[0] * 2000 + x[1])
		#print(pos)
		for i in range(n-2):
			if pos[i+2][1] < pos[i][1] and pos[i+2][0] - pos[i][0] <= 5:
				flag = False
				break
			if i+3 < n and pos[i+1][0] - pos[i][0] < 5 and \
					       pos[i+2][0] - pos[i+1][0] <= 5 and \
					       pos[i+3][0] - pos[i+2][0] < 5 and \
					       pos[i+2][1] >= pos[i+3][1] and \
					       pos[i+1][1] > pos[i+2][1] and \
					       pos[i+1][1] > pos[i][1]: 
				flag = False
				break
		if not flag:
			ans += str(k)
			break
	if flag:
		ans += "Possible"
	print (ans)
