
fin = open("in.txt","r")


N = int(fin.readline())


f = open( "out.txt","w")




for T in range(N):
	(K,L,S) = map(int,fin.readline().split())
	keys = list(fin.readline().rstrip())
	target = list(fin.readline().rstrip())
	bananas = S/L
	p = 1.0

	for t in target:
		count = len([i for i in keys if i == t])
		if count ==0 :
			bananas = 0
			p = 0.0
			break	
		p *= float(count)/K

	if bananas > 0:
		p = p*bananas

	r = bananas - p
	
	f.write("Case #{}: {}\n".format(T+1,r))

f.close()

fin.close()