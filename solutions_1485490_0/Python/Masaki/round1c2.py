def optimum(boxes,toys):
	cnt=0
	if boxes==[] or toys==[]:
		return(0)
	if boxes[0][1]==toys[0][1]:
		cnt=cnt+min(boxes[0][0],toys[0][0])
		cnt=cnt+optimum(boxes[1:],toys[1:])
	else:
		a1=optimum(boxes[1:],toys)
		a2=optimum(boxes,toys[1:])
		cnt=cnt+max(a1,a2)
	return(cnt)



inp=open("abcd.in","r")
out=open("outp.txt","w")
T=int(inp.readline().strip())

for i in range(1,T+1):
	size=inp.readline().strip().split(" ")
	N=int(size[0])
	M=int(size[1])
	lines=inp.readline().strip().split(" ")
	boxes=[]
	for k in range(0,2*N,2):
		j=(int(lines[k]),int(lines[k+1]))
		boxes.append(j)
	
	lines=inp.readline().strip().split(" ")
	toys=[]
	for k in range(0,2*M,2):
		j=(int(lines[k]),int(lines[k+1]))
		toys.append(j)
	M=optimum(boxes,toys)
	out.write("Case #"+str(i)+": "+str(M)+"\n")
out.close()
inp.close()
