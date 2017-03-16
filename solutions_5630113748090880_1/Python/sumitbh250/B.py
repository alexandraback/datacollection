t = int(raw_input())
for i in xrange(1,t+1):
	n = int(raw_input())
	num = [0 for j in xrange(2501)]
	for j in xrange(2*n-1):
		abc = map(int,raw_input().split())
		for j in abc:
			num[j]+=1
	ans = ''
	for j in xrange(2501):
		if(num[j]%2==1):
			ans=ans+str(j)+" "
	print("Case #"+str(i)+": "+ans)
