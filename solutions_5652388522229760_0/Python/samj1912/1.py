def func(a):
	x=[0 for i in range(10)]
	t=1
	n=a
	while(t):
		arr=map(int,list(str(n)))
		# print arr
		for i in range(len(arr)):
			x[arr[i]]=1
		for i in range(10):
			if x[i]==0:
				break
			if i==9:
				return n
		# print x		
		n+=a			


						


t=input()
for i in range(t):
	n=input()
	print "Case #"+str(i+1)+":",
	if n==0:
		print "INSOMNIA"
	else:
		print func(n)	
