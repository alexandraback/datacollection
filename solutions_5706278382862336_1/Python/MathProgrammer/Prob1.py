
def gcd(a,b):
	if not b:
		return(a)
	return(gcd(b,a%b))
	
twos=[1 for i in range(40)]
for i in range(1,40):
	twos[i]*=2*twos[i-1]

f=open("A-large.in","r")
T=int(f.readline())
answers=[0 for i in range(T)]
for i in range(T):
	[top,bottom]=f.readline().strip().split("/")
	top=int(top)
	bottom=int(bottom)
	g=gcd(top,bottom)
	(top,bottom)=(top//g,bottom//g)
	if not bottom in twos:
		answers[i]="impossible"
	else:
		for j in range(39):
			if top*twos[j]>=bottom:
				answers[i]=j
				break
f.close()


f=open("OUTPUT.txt","w")
for i in range(T):
	f.write("Case #{}: {}\n".format(i+1,answers[i]))
f.close()
