def func(x):
	z=""
	for i in range(len(x)):
		if z+x[i] > x[i]+z:
			z=z+x[i]
		else:
			z=x[i]+z	
	return z
	
t=input()

for i in range(t):
	x=raw_input()
	print "Case #"+str(i+1)+": "+func(x)	