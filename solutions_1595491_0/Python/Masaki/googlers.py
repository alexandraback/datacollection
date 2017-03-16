def best(x,y,p,l):
	m=0
	if p==0:
		return(x)
	for i in range(0,x):
		if (l[i]>0) and (l[i]>=3*p-2):
			m=m+1
		elif (l[i]>0) and (y>0) and (l[i]==3*p-3 or l[i]==3*p-4):
			m=m+1
			y=y-1
	return(m)
file=input("filename\n")
inp=open(file,"r")
n=int((inp.readline()).strip())
out=open("googlers.txt","w")
for i in range(1,n+1):
	st=((inp.readline()).strip()).split(" ")
	for j in range(0,len(st)):
		st[j]=int(st[j])
	fg=best(st[0],st[1],st[2],st[3:])
	out.write("Case #"+str(i)+":"+" "+str(fg)+"\n")
out.close()
inp.close()
	