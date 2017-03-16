def first(fname):
	lines = [line.strip() for line in open(fname)]
	T = int(lines[0])
	outText=""
	for i in range(T):
		(A, B)=[int(c) for c in lines[1+2*i].split()]
		P =[float(c) for c in lines[2+2*i].split()]
		prod =float(B+1)
		floor = float(2*B - A +2)
		minE = float(B+2)
		for j in range(A):
			prod *=P[j]
			exp = (floor +2*(A-j-1) - prod)
			if minE > exp:
				minE = exp
		outText = outText +"Case #"+str(i+1)+": "+str(minE)+"\n"
	outFile = open("out.txt", 'w')
	outFile.write(outText)
	outFile.close()
