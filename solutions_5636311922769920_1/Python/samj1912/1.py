def func(x):
	k=x[0]
	c=x[1]
	s=x[2]
	z=k**(c-1)
	ma=z*k

	if z==1:
		if s<k:
			return "IMPOSSIBLE"
		else:
			arr=[str(i+1) for i in range(s)]
			return " ".join(arr)
	else:
		if s < ((k+1)/2):
			return "IMPOSSIBLE"
		if s==k:
			arr=[str(i+1) for i in range(s)]
			return " ".join(arr)
			
		else:	
			arr=[]
			p=2
			for i in range(((k+1)/2)):
				if p<=ma:
					arr.append(str(p))
				else:
					arr.append(str(ma))	
				p+=2
				p+=z*2

			return " ".join(arr)	



n=input()
for i in range(n):
	inp=map(int,raw_input().split())
	print "Case #"+str(i+1)+":",
	print func(inp)