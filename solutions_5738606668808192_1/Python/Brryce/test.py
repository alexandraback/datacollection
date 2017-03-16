import sys

N = int(sys.stdin.readline().strip())
for qw in range(1,N+1):
	print("Case #%d:"%qw)
	"""
	i find out that if the first half of the string equals the 2nd half,
	 the string must be qualified, so we can generate 500 such strings.\
	 solve the problem prefectly 

	"""
	tmp = sys.stdin.readline().strip().split()
	n = int(tmp[0])//2# since we know n = 16, we did not consider if it's odd
	j = int(tmp[1])
#since the result have same diviser, we can generate them before
	result = []
	for base in range(2,11):
		# get each based number
		result.append(1+base**n)
	sr = " ".join(str(num) for num in result)

	count = 0
	for i in range(2**(n-2)):
		if count == j:
			break
		#get a sample of list
		ll=[1]
		ii = i
		for k in range(n-2):
			ll.append(ii%2)
			ii = ii//2
		ll.append(1)


		# append ll
		for num in ll.copy():
			ll.append(num)
		print("%s %s"%("".join(str(num) for num in ll),sr))
		count +=1

			