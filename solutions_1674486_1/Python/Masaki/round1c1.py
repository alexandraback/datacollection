G={}
size=0
mark=[]

def explore(v):
	global count
	global mark
	mark[v]=1
	for i in G[v]:
		if mark[i]==1:
			raise Exception
		if mark[i]==0:
			explore(i)

def DFS():
	global mark
	for i in range(1,size+1):
		mark=["*"]
		mark.extend([0]*size)

		mark[i]=1

		try:
			explore(i)
		except:
			return("Yes")

	return("No")

inp=open("abc.in","r")
out=open("outp.txt","w")
T=int(inp.readline().strip())

for i in range(1,T+1):
	G={}
	size=int(inp.readline().strip())
	for k in range(1,size+1):
		lines=inp.readline().strip().split(" ")
		del(lines[0])
		for j in range(0,len(lines)):
			lines[j]=int(lines[j])
		G[k]=lines
	mark=["*"]
	mark.append([0]*size)
	M=DFS()
	out.write("Case #"+str(i)+": "+M+"\n")
out.close()
inp.close()
