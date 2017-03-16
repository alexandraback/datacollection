
fin = open("in.txt","r")


N = int(fin.readline())


f = open( "out.txt","w")




for T in range(N):
	(R,C,W) = map(int,fin.readline().split())
	p = 0
	if C>=W:
		p = C/W
		p *= R
		p+= (W-1)
		variation = C%W
		if variation != 0:
			p += 1
	

	
	f.write("Case #{}: {}\n".format(T+1,p))

f.close()

fin.close()