def comp(x, y):
	if x[1]>y[1]:
		return 1
	else:
		if x[1]<y[1]:
			return -1
		else:
			return 0
			
def update_ans(ans, filler, old, new, sour):
	#print "got %s, %s, %d, %d, %d" % (ans, filler, old, new, sour)
	if sour > (new-old)*len(filler):
		for x in filler:
			ans[x[0]-1]+=new-old
		return sour - (new-old)*len(filler)
	else:
		for x in filler:
			ans[x[0]-1]+=float(sm)/len(filler)
		return 0

inf = open("A-large.in", "r")
ouf = open("A-large.out", "w")
n = int(inf.readline())
for j in range(n):
	t = map(int, inf.readline().split())[1:]
	sm = sum(t)
	mks = []
	for i, x in enumerate(t):
		mks.append([i+1, x])
	mks.sort(comp)
	
	ans = [0]*len(mks)
	filler = []
	for x in mks:
		if len(filler)==0 or x[1] == filler[-1][1]:
			filler.append(x)
		else:
			sm = update_ans(ans, filler, filler[-1][1], x[1], sm)
			filler.append(x)
		if sm == 0:
			break
		print sm
	print ans
	if sm > 0:
		ans = [x+float(sm)/len(ans) for x in ans]
	print ans
	ans = [100*float(x)/sum(ans) for x in ans]
	print ans
	ouf.write("Case #%d: %s\n" % (j+1, ' '.join(map(str, ans))))
inf.close()
ouf.close()
