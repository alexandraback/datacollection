NumberOfTestCases = int( input() )
for NumTestCases in range(1,NumberOfTestCases+1):
	
	D = int(input())
	P = input().split()
	for i in range(0,D):
		P[i] = int(P[i])
	ans = 1000
	for i in range(1,1001):
		count = i
		for x in P:
			count += (x-1)//i
		if count < ans:
			ans = count
	print('Case #',NumTestCases,': ',sep='',end='')
	print(ans)
