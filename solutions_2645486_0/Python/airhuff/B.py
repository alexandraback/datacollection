inp = open("file2.txt").read().splitlines()
outp = open("out2.txt","w")

def demax(A,R,mlist,N,E):
	if A > E:
		A = E
	if len(mlist) == N+1:
		return A*mlist[N]
	mmax = 0
	for i in range(0,A+1):
		msum = demax(A-i+R,R,mlist,N+1,E) + (i*mlist[N])
		if msum > mmax:
			mmax = msum
	return mmax

i = 1
count = 1
while i < len(inp):
	mlist = list(map(int,inp[i].split()))
	R = mlist[1]
	A = mlist[0]
	i += 1
	mlist = list(map(int,inp[i].split()))
	outp.write("Case #"+str(count)+": "+str(demax(A,R,mlist,0,A))+"\n")
	i += 1
	count += 1
