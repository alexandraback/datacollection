matched=[]
nums=list(range(10))

def alleven(k):
	for i in k:
		if i%2!=0:
			return False
	return True
	
def allodd(k):
	for i in k:
		if i%2==0:
			return False
	return True

f=int(input(''))
track=True
for x in range(f):
	nums=list(range(10))
	n=input('')
	count=2
	num=int(n)
	track=True
	while track:
		for i in str(num):
			#input('')
			#print(i,' ',nums)
			i=int(i)
			if num==0:
				print('Case #{}: INSOMNIA'.format(str(x+1)))
				track=False
				break
			if i in nums:
				matched+=[i]
				nums=nums[:nums.index(i)]+nums[nums.index(i)+1:]
			if (nums==[]):
				print('Case #{}: {}'.format(str(x+1),str((count-1)*int(n))))
				track=False
				break
		num=count*int(n)
		count+=1
	
