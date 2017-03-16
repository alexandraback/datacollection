t = input()
for i in range(t):
	b = raw_input()
	b = b.split()
	a = b[0]

	n = b[1]
	n = int(n)

	l = len(a)
	
	substr = []
	for j in range(1, l+1):
		end = l+2 - j
		for k in range(end-1):
			substr.append(a[k:k+j])
			
	#substr = list(set(substr))
	#print  substr
	count = 0
	for j in range(len(substr)):
		x = substr[j]
		temp = 0
		maxx = 0
		
		for k in range(len(x)):
			if x[k]=='a' or x[k]=='e' or x[k]=='i' or x[k]=='o' or x[k]=='u' :
				if temp > maxx :
					maxx = temp
				temp = 0
			else:
				temp += 1
				
		if temp > maxx :
			maxx = temp
		
		if maxx >= n:
			count+=1
			
	print "Case #%d: %d" % (i+1, count)

