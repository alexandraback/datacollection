f=open("B-small-attempt0.in","r")
g=open("B-small-attempt0.out","w")

T=int(f.readline()) 
for t in xrange(1,T+1):
	g.write("Case #"+str(t)+": ")
	[x,y]=[int(a) for a in f.readline().split()]

	for i in xrange(abs(x)):
		if x<0:
			g.write("EW")
		else:
			g.write("WE")

	for i in xrange(abs(y)):
		if y<0:
			g.write("NS")
		else:
			g.write("SN")

	g.write("\n")

f.close
g.close