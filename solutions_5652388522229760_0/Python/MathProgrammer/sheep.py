
def SOLVE(N):
	if N==0:
		return "INSOMNIA"
	digits=[0]*10
	sum=0
	R=N
	while sum<10:
		M=R
		while M>0:
			if digits[M%10]==0:
				sum+=1
				digits[M%10]=1
				if sum==10:
					return R
			M//=10
		R+=N
	return R-N

f=open("A-small-attempt0.in","r")
g=open("google.out","w+")
T=int(f.readline())

for i in range(T):
	N=int(f.readline())
	ans=SOLVE(N)
	g.write("Case #{}: {}\n".format(i+1,ans))

g.close()
f.close()




