def primecheck(x):
	t=(int(x**0.5)/6)+1
	if x%2==0:
		return 2
	if x%3==0:
		return 3	
	for i in xrange(1,100):

		if x%(6*i-1)==0:
			return 6*i-1
		if x%(6*i+1)==0:
			return 6*i+1	
	return 0			

def bin_add(x,y): 
	return bin(int(x, 2) +int(y,2))[2:]
def ppcheck(x):
	arr=[]
	for i in range(2,11):
		# print int(x,i)
		arr.append(primecheck(int(x,i)))
		# print arr[-1]
		if arr[-1]==0:
			break
	return arr	
		
			
def func(x):
	l=x[0]
	n=x[1]
	inp="1"
	for i in range(l-2):
		inp+="0"
	inp+="1"	
	count=0
	arr=[]
	while(count<n and len(inp)<=l):	
		parr=ppcheck(inp)
		if reduce(lambda x,y:x*y,parr)==0:
			pass
		else:
			arr.append([inp,parr])
			count+=1
			# print arr[-1]
		inp=bin_add(inp,"10")
		# print inp	

	return arr			




x=input()
for i in range(x):
	arr = map(int,raw_input().split())
	print "Case #1:"
	z=func(arr)
	for j in z:
		print j[0],
		for k in range(9):
			print j[1][k],
		print ""	
