from math import *
c=int(input().strip())
for x in range(c):
	result=0
	n,m,k=input().strip().split()
	n,m,k = int(n),int(m),int(k)

	if min(n,m)<=2:
		print('Case #', x+1, ': ', k, sep='')
		#print()
		continue
	if k<=4:
		print('Case #', x+1, ': ', k, sep='')
		#print()
		continue
#	if k>m*n-4:
#		result=k-(m*n-4)
#		k=m*n-4
	a=1
	b=1
	done=0

	if k+4>m*n:
		q = k+4-m*n
		print('Case #', x+1, ': ', (m-2)*2+(n-2)*2+q, sep='')
		continue

	while min(a,b) <= min(m,n):
		
		if (a*b)-4 >= k:
			done=1
			#print(a,b,k)
			print('Case #', x+1, ': ', (a-2)*2+(b-2)*2, sep='')
			break
		if (a*b)-3 > k:
			done=1
			#print(a,b,k)
			print('Case #', x+1, ': ', (a-2)*2+(b-2)*2+1, sep='')
			break

		a += 1
		q,w=a,b
		a=min(q,w)
		b=max(q,w)

	if done == 1: continue

	k+=4
	k=ceil(k/min(m,n))
	result= (min(m,n)-2)*2+(k-2)*2
	print('Case #', x+1, ': ', result, sep='')
