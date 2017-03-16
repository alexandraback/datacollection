f = open('3.out','w')

def check(a):
	print ''.join(map(lambda x:str(x),a)),base10(a,2)%3,base10(a,3)%2,base10(a,4)%5,base10(a,5)%2,base10(a,6)%7,base10(a,7)%2,base10(a,8)%9,base10(a,9)%2,base10(a,10)%3
	return 0

def base10(arr,x):
	mult=1
	value=0
	for i in range(len(arr)-1,-1,-1):
		#print mult, i, value, arr[i]
		value=value+arr[i]*mult
		mult=mult*x
	#print arr, x, value
	return value


def trial(a):
	count=0
	d=[3,2,5,2,7,2,9,2,3]
	for i in range(1,31,2):
		for j in range(i+2,31,2):
			for k in range(2,31,2):
				for l in range(k+2,31,2):
					a[i]=1
					a[j]=1
					a[k]=1
					a[l]=1
					count = count+1
					#print count
					#check(a)
					result=''.join(map(lambda x: str(x), a))+" "+' '.join(map(lambda x: str(x), d)) 
					f.write(result+'\n')
					print result


					a[i]=0
					a[j]=0
					a[k]=0
					a[l]=0

					if count==500:
						return

l=32
j=50
count=0
a=[0]*l
a[0]=1
a[len(a)-1]=1
result = "Case #1: "
f.write(result+'\n')
trial(a)
#trial2()
#while(count<j):
#	d=[]
#	print count, a
	# if(check(a)==1):
	# 	result=''.join(map(lambda x: str(x), a))+" "+' '.join(map(lambda x: str(x), d)) 
	# 	f.write(result+'\n')
	# 	print result
	# 	count=count+1
	#generateNext(a)
	#i=i+10

	
f.close()