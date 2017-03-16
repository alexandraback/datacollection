lines=open("x")
for case,line in enumerate(lines):
	x = line.split()[1].strip()
	sum, bum = 0, 0	
	for a,b in enumerate(x):
		b=int(b)
		if a>sum and b:
			bum, sum = a-sum, a-sum
		sum+=b
	print "Case "+chr(35)+str(case+1)+": "+str(bum)
