#MMM, Google Code Jam Problem 4, War

infile = open("D-small-attempt0.in", "r")
outfile = open("output.txt", "w")

numtests = int(infile.readline())

for T in range(numtests):
	
	N = int(infile.readline())

	Naomi = map(float, infile.readline().split(' '))
	Ken = map(float, infile.readline().split(' '))

	Naomi.sort(key=float)
	Ken.sort(key=float)

	#Deceitful War
	dn = list(Naomi)
	dk = list(Ken)

	for n_item in dn:
		for k_item in dk:
			if n_item>k_item:
				dk.remove(k_item)
				break

	dwins = len(dn)-len(dk)

	#Honest War
	hn = list(Naomi)
	hk = list(Ken)

	for n_item in hn:
		if hk[-1]>n_item:
			for k_item in hk:
				if k_item > n_item:
					hk.remove(k_item)
					break
		else:
			break

	hwins = len(hk)

	#Output
	outfile.write("Case #"+str(T+1)+": "+str(dwins)+" "+str(hwins)+"\n")