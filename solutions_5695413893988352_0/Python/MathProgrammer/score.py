from sys import*

f=open("B-small-attempt0.in","r+")
g=open("output.txt","w+")

T=int(f.readline())

for i in range(T):
	[C,J]=[i for i in f.readline().split()]
	a=""
	b=""
	pos=0
	plus=0 #1 if C>J, -1 if C<J, 0 if in balance
	while pos<len(C):
		if C[pos]!="?" and J[pos]!="?":
			a+=C[pos]
			b+=J[pos]
			if C[pos]>J[pos]:
				plus=1
			elif C[pos]<J[pos]:
				plus=-1
			pos+=1
		elif C[pos]=="?" and J[pos]=="?":
			if plus==0:
				a+="0"
				b+="0"
				pos+=1
			elif plus>0:
				a+="0"
				b+="9"
				pos+=1
			else:
				a+="9"
				b+="0"
				pos+=1
		elif C[pos]=="?" and J[pos]!="?":
			if plus>0:
				a+="0"
				b+=J[pos]
				pos+=1
			elif plus<0:
				a+="9"
				b+=J[pos]
				pos+=1
			else:
				a+=J[pos]
				b+=J[pos]
				pos+=1
		elif C[pos]!="?" and J[pos]=="?":
			if plus>0:
				b+="0"
				a+=C[pos]
				pos+=1
			elif plus<0:
				b+="9"
				a+=C[pos]
				pos+=1
			else:
				a+=C[pos]
				b+=C[pos]
				pos+=1
				
	g.write("Case #{}: {} {}\n".format(i+1,a,b))

f.close()
g.close()
