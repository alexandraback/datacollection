from sys import*

def solve(B,M):
	global matrix
	if M==2**(B-2):
		for i in range(B):
			for j in range(B):
				if j>i:
					matrix[i][j]=1
		return
	
	for i in range(B):
		for j in range(B-1):
			if j>i:
				matrix[i][j]=1
	
	n=2**(B-3)
	ind=B-2
	
	while M>0:
		if M>=n:
			M-=n
			matrix[ind][B-1]=1
		n//=2
		ind-=1
	
	return
	

f=open("B-large.in","r+")
g=open("output.txt","w+")

T=int(f.readline())

for i in range(1,1+T):
	[B,M]=[int(i) for i in f.readline().split()]
	
	matrix=[[0 for i in range(B)] for i in range(B)]
	
	if M>2**(B-2):
		ans="IMPOSSIBLE"
	else:
		ans="POSSIBLE"
		solve(B,M)
	
	g.write("Case #{}: {}\n".format(i,ans))
	
	if ans[0]=="P":
		for j in range(B):
			for k in range(B):
				g.write("{}".format(matrix[j][k]))
			g.write("\n")


f.close()
g.close()