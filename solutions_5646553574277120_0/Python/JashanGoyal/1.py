import sys
sys.stdin=open('in','r')
sys.stdout=open('out','w')
for num in range(input()):
	a,b,c  =map(int,raw_input().split())
	arr = map(int,raw_input().split())
	s=[]
	max_range=0	
	for i in range(len(arr)):
		if arr[i]<=max_range:
			max_range+=arr[i]
		else:
			for j in range(max_range+1,arr[i]):
				if j<=max_range:continue
				if max_range>=arr[i]:
					break
				s.append(j)
				max_range += j
			max_range+=arr[i]
	for i in range(1,c+1):
		if i<=max_range:
			continue
		else:
			s.append(i)
			max_range+=i
	# print s
	ans = len(s)
	print "Case #"+str(num+1)+": "+str(ans)