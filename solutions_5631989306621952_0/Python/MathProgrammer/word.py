from sys import*

def SOLVE(S):
	RES=S[0]
	for i in range(1,len(S)):
		if S[i]>=RES[0]:
			RES=S[i]+RES
		else:
			RES=RES+S[i]
	return RES
		

f=open("A-small-attempt0.in","r")
g=open("google.out","w+")
T=int(f.readline())

for i in range(T):
	S=f.readline()
	g.write("Case #{}: {}".format(i+1,SOLVE(S)))

f.close()