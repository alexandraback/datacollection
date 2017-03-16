T = int(input())

for c in range(T):
	N=int(input())
	D=[False]*10
	C,j=0,0
	if N == 0:
		print("Case #%d: INSOMNIA" % (c+1))
		continue		
		
	while C < 10:
		j += 1
		NS=str(j*N)
		for d in range(10):
			if not D[d] and str(d) in NS:
				D[d] = True
				C += 1
				if C == 10:
					break
	print("Case #%d: %d" % (c+1,j*N))
			
