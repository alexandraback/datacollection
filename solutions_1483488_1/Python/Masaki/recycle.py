import math
def total(a,b):
	count=0
	digits=int(math.log10(a))+1
	for i in range(a,b+1):
		l=[]
		for j in range(1,digits+1):
			tens=(10**(digits-j+1))
			k=i//tens
			m=i%tens
			nu=(m*(10**(j-1)))+k
			if (i<nu<=b) and not(nu in l):
				l.append(nu)
				count=count+1
	return(count)


inp=open("re.in","r")
n=int((inp.readline()).strip())
out=open("recyclelarge.txt","w")
for i in range(1,n+1):
	st=((inp.readline()).strip()).split(" ")
	fg=total(int(st[0]),int(st[1]))
	out.write("Case #"+str(i)+":"+" "+str(fg)+"\n")
out.close()
inp.close()