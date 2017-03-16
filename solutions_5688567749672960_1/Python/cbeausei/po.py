fin=open("C:/users/Clement/Desktop/bla.txt","r")
fout=open("C:/users/Clement/Desktop/output.txt","w")

s=fin.read().split("\n")
z=int(s[0])

def inv(s):
	t=""
	for i in range(len(s)):
		t+=s[len(s)-1-i]
	return(t)

def go10(x):
	v=0
	h=x//2
	v+=10**h
	v-=1
	v+=1
	v+=10**(x-h)
	v-=2
	v+=1
	return(v)

for i in range(z):
	n=int(s[i+1])
	p=int(inv(s[i+1]))
	m=len(s[i+1])
	v=0
	if (m==1 or n==10):v=n
	else:
		if (n%10)==0:
			v=1
			n-=1
			g=str(n)
			p=int(inv(g))
			m=len(g)
		v+=10
		for j in range(m-2):
			v+=go10(j+2)
		h=m//2
		if ((n//(10**(m-h)))==(10**(h-1))):
			v+=(n%(10**(m-h)))
		else:
			v+=(p%(10**h))
			v+=1
			v+=(n%(10**(m-h)))-1
	print(v)
	fout.write("Case #"+str(i+1)+": "+str(v)+"\n")