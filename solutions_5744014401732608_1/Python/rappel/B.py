fin=open('b_large.in','r')
fout=open('b_large.out','w')

T=int(fin.readline())

for t in range(T):
	temp=fin.readline().split()
	B=int(temp[0])
	M=int(temp[1])
	if M>2**(B-2):
		fout.write("Case #%d: IMPOSSIBLE\n" % (t+1))
		continue
	adj=[[0 if j<=i else 1 for j in range(B)] for i in range(B)]
	M0=M-1
	for i in range(B-1):
		if int((M-1)//2**i)%2==0:
			adj[0][B-i-2]=0
	fout.write("Case #%d: POSSIBLE\n" % (t+1))
	s=""
	for i in range(B):
		for j in range(B):
			s+=str(adj[i][j])
		s+="\n"
	fout.write(s)
fin.close()
fout.close()