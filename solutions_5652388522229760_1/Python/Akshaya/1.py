
n=[]
f = open('1.out','w')
fin = open('1.in','r')
t=int(fin.readline().strip())
for i in range(t):
	n.append(int(fin.readline().strip()))
fin.close()
for j in range(t):

	if n[j]==0:
		result = "Case #"+str(j+1)+": INSOMNIA"
		print result
		f.write(result+'\n')
	
	else:
		count = range(10)
		i=1

		while len(count)>0:
			num=n[j]*i
			#print num

			while(num!=0):
				if num%10 in count:
					count.remove(num%10)
					#print num%10,
				num=num/10
			i=i+1
			#print
			#print range(10)
			#print count
		result = "Case #"+str(j+1)+": "+str(n[j]*(i-1))
		print result
		f.write(result+'\n')
f.close()