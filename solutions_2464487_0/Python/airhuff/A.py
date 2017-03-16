inp = open("file1.txt").read().splitlines()
outp = open("out1.txt","w")

for i in range(1,len(inp)):
	mlist = inp[i].split()
	r = int(mlist[0]) + 1
	t = int(mlist[1])
	msum = 0
	while 2*r-1 <= t:
		msum += 1
		t -= 2*r-1
		r += 2
	outp.write("Case #"+str(i)+": "+str(msum)+"\n")
