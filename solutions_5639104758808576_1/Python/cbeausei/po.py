fin=open("C:/users/Clement/Desktop/bla.txt","r")
fout=open("C:/users/Clement/Desktop/output.txt","w")

s=fin.read().split("\n")
n=int(s[0])
for i in range(n):
	t=s[i+1].split(" ")
	m=int(t[0])
	x=[0]*(m+1)
	for j in range(m+1):
		x[j]=int(t[1][j])
	v=0
	k=x[0]
	for j in range(1,m+1):
		if j-k>v:v=j-k
		k+=x[j]
	fout.write("Case #"+str(i+1)+": "+str(v)+"\n")