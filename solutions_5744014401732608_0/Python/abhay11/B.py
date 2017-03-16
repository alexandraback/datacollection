numRuns = int(input())
for run in range(numRuns):
	data = input().split()
	n = int(data[0])
	k = int(data[1])
	if k>2**(n-2):
		print("Case #"+str(run+1)+": IMPOSSIBLE")
	else:
		print("Case #"+str(run+1)+": POSSIBLE")
		print((format(k-1,'b')+'1').rjust(n,'0'))
		for i in range(1,n):
			print(('0'*(i+1))+('1'*(n-i-1)))
		
		