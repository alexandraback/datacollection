n=[]
f = open('2.out','w')
fin = open('2.in','r')
t=int(fin.readline().strip())
for i in range(t):
	n.append(list(fin.readline().strip()))
fin.close()


def findsad(arr):
	for i in range(len(arr)-1, -1, -1):
		if(arr[i]=='-'):
			return i
	return -1

def findhappy(arr):
	for i in range(0, len(arr)):
		if(arr[i]=='-'):
			return i-1
	return -1

def flip(arr, stop):
	i=0
	j=stop
	while (i<=j):
		temp=arr[j]
		if(arr[i]=='+'):
			arr[j]='-'
		else:
			arr[j]='+'
		if(temp=='+'):
			arr[i]='-'
		else:
			arr[i]='+'
		i=i+1;
		j=j-1;

#print n
for j in range(t):
	flipcount=0
	while(findsad(n[j])!=-1):
		print n[j]
		if(n[j][0]=='+'):			
			flip(n[j],findhappy(n[j]))
		else:
			flip(n[j],findsad(n[j]))
		flipcount=flipcount+1

	result = "Case #"+str(j+1)+": "+str(flipcount)
	print result
	f.write(result+'\n')
f.close()