highest_gain=-1
start_E=-1
def backtrack(E,R,V,i,G):
	#print G
	global start_E
	global highest_gain
	if (E>start_E):
		return
	if (i==len(V)):
		if (G>highest_gain):
			highest_gain=G
		return
	for ii in range(E+1):
		if (E-ii >=0):
			backtrack(E-ii+R,R,V,i+1,G+V[i]*ii)

inp = file("B-small-attempt0.in")
out = file("B-small-out.txt",'w')
T=int(inp.readline().strip())
for aa in range(T):
	E,R,N=map(int,inp.readline().split())
	V=map(int,inp.readline().split())
	highest_gain=-1
	start_E=E
	backtrack(E,R,V,0,0)
	out.write("Case #%d: %d\n"%(aa+1,highest_gain))
out.close()
inp.close()