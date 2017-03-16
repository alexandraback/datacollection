f = open('3.out','w')

def trial(a):
	count=0

	for i in range(1,15,2):
		for j in range(i+2,15,2):
			for k in range(2,15,2):
				for l in range(k+2,15,2):
					a[i]=1
					a[j]=1
					a[k]=1
					a[l]=1
					count = count+1
					print count
					check(a)

					a[i]=0
					a[j]=0
					a[k]=0
					a[l]=0

def trial2():
	count=0
	d=[3,2,5,2,7,2,9,2,3]
	a=[1]*16
	for i in range(1,15,2):
		for j in range(i+2,15,2):
			for k in range(2,15,2):
				for l in range(k+2,15,2):
					a[i]=0
					a[j]=0
					a[k]=0
					a[l]=0
					count = count+1
					#print count
					check(a)
					result=''.join(map(lambda x: str(x), a))+" "+' '.join(map(lambda x: str(x), d)) 
					f.write(result+'\n')
					print result

					a[i]=1
					a[j]=1
					a[k]=1
					a[l]=1

					if(count==50):
						return




trial2()

f.close()