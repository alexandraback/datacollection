def func(a):
	count=0
	for i in range(len(a)-1):
		if a[i]!=a[i+1]:
			count+=1

	if a[-1]=='-':
		count+=1
	return count				
						


t=input()
for i in range(t):
	s=raw_input()
	print "Case #"+str(i+1)+":",
	print func(s)
