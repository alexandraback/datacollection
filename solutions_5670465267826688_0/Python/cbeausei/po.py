fin=open("C:/users/Clement/Desktop/bla.txt","r")
fout=open("C:/users/Clement/Desktop/output.txt","w")

def conv(a):
	if a=="i":return(0)
	if a=="j":return(1)
	if a=="k":return(2)

def mult(a,b,signe):
	if a==b and a!=3:return(3,1-signe)
	if a==b==3:return(3,signe)
	if a==3:return(b,signe)
	if b==3:return(a,signe)
	if ((b-a)%3)==1:return(((b+1)%3),signe)
	return(((b-1)%3),1-signe)
	
def calc(t,a,b):
	x=3
	signe=0
	for i in range(a,b+1):
		(x,signe)=mult(x,t[i],signe)
	return(x,signe)
	
	
s=fin.read().split("\n")
z1=int(s[0])
for z in range(1,z1+1):
	n,x=map(int,(s[2*z-1]).split(" "))
	if x>12:
		x=8+(x%4)
	t=[(0,0)]*(n*x)
	m=n*x
	v="NO"
	
	for i in range(x):
		for j in range(n):
			t[i*n+j]=(conv(s[2*z][j]),0)
	
	for i in range(1,m):
		(a,sa)=t[i-1]
		(b,sb)=t[i]
		t[i]=mult(a,b,sa)
		
	if t[m-1]==(3,1):
		i=0
		while v=="NO" and i<m-2:
			if t[i]==(0,0):
				j=i+1
				while v=="NO" and j<m-1:
					if t[j]==(2,0):v="YES"
					j+=1
			i+=1
	
	fout.write("Case #"+str(z)+": "+v+"\n")
	print(v)