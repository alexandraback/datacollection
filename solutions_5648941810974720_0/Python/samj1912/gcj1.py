def func(x):
	a=[0 for i in range(10)]
	a[0]=x.count('Z')
	a[2]=x.count('W')
	a[3]=x.count('H')-x.count('G')
	a[4]=x.count('U')
	a[5]=x.count('F')-a[4]
	a[6]=x.count('X')
	a[7]=x.count('S')-a[6]
	a[8]=x.count('G')
	a[1]=x.count('O')-a[0]-a[2]-a[4]
	a[9]=x.count('I')-a[5]-a[6]-a[8]
	x=""
	for i in range(10):
		x+=str(i)*a[i]

	return x
	
n=input()
for i in range(n):
	s=raw_input()
	print "CASE #"+str(i+1)+": "+func(s)
	