NumberOfTestCases = int( input() )
for NumTestCases in range(1,NumberOfTestCases+1):
	print('Case #',NumTestCases,': ',sep='',end='')
	
	Smax,str=input().split()
	Smax=int(Smax)
	ans = 0
	sum = 0
	for i in range(0,Smax+1):
		if sum < i:
			ans += 1
			sum += 1
		sum += int(str[i])
	print(ans)
