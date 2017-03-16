f=open('t.txt','r')
g=open('file.txt','w')

def mergesort(n,x):
	if len(n) > 1:
		mid = len(n) // 2
		a = n[:mid]
		b = n[mid:]
		if len(a) > 1: a = mergesort(a,x)
		if len(b) > 1: b = mergesort(b,x)
		return merge(a, b,x)
	else:
		return n	
	
def merge(a, b,x):
	result = []
	while a and b:
		if a[0][x] <= b[0][x]:
			result.append(a[0])
			a = a[1:]
		else:
			result.append(b[0])
			b = b[1:]
	if a:
		result.extend(a)
	else:
		result.extend(b)
	return result


for i in range(1,1+int(f.readline())):
	nums=[float(j) for j in f.readline().split()[1:]]
	tot=0
	for j in nums:
		tot+=j
	tot1=tot*2.0
	target=(tot1)/len(nums)
	#print target
	nums1=[]
	for j in range(len(nums)):
		nums1.append([nums[j],j])
	nums1=mergesort(nums1,0)
	j=len(nums1)-1
	while j>-1 and nums1[j][0]>target:
		#print nums1[j][0],target
		tot1-=nums1[j][0]
		#print tot
		target=tot1/(j)
		#print target
		j-=1
	nums1=mergesort(nums1,1)
	ans=[]
	for j in nums1:
		if j[0]>=target:
			ans.append(0)
		else:
			ans.append(100*(target-j[0])/tot)
	print 'Case #' + str(i) + ':',
	g.write('Case #' + str(i) + ':' + ' ')
	for j in ans:
		print j,
		g.write(str(j) + ' ')
	g.write('\n')
	print

g.close()