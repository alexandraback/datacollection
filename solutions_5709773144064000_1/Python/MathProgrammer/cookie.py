
f=open("B-large.in","r")
T=int(f.readline().strip())
answers=[-1 for i in range(T)]

for i in range(T):
	(C,F,X)=tuple([float(j) for j in list(f.readline().split())])
	currentBest=X/2
	namnare=2
	Csum=0
	while True:
		Csum+=C/namnare
		namnare+=F
		if Csum+X/namnare<currentBest:
			currentBest=Csum+X/namnare
		else:
			break
	answers[i]=currentBest
f.close()

f=open("OUTPUT.txt","w")
for i in range(T):
	f.write("Case #{}: %.7f\n".format(i+1) %answers[i]);
f.close()
