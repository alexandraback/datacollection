test=input()
ind =0
while test>0:
	ind=ind+1
	test=test-1
	strr=raw_input()
	arr=list(strr)
	a=[]
	#print arr
	a.append(arr[0])
	arr.pop(0)
	for k in arr:
		if(k>=a[0]):
			a.insert(0,k)
		else:
			a.append(k)
	
	ans=''.join(a)
	
	print "Case #"+str(ind)+": "+ans
