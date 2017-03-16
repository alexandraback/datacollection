f=open("A-large.in")
w=open("A-large.out","w")
T=int(f.readline())
for test in range(T):
	Smax,S=f.readline().split()
	count=0
	S=[int(i) for i in S]
	for i in range(len(S)):
		if sum(S[:i])<i:
			count+=1
			S[i]+=1
	w.write("Case #{}: {}\n".format(test+1,count))
w.close()
