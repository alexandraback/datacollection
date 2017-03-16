def reverse(num):
	result=0
	while num:
		result=result*10+num%10
		num=num/10
	return result

t=input()
lst=[-1 for x in xrange(10**6+1)]
for j in xrange(10):
	lst[j]=j
for j in xrange(10,len(lst)):
	if lst[reverse(j)]==-1 or j%10==0:
		lst[j]=lst[j-1]+1
	else:
		lst[j]=min(lst[reverse(j)]+1,lst[j-1]+1)

for i in xrange(t):
	n=input()
	print 'Case #%d: %d' %(i+1, lst[n])