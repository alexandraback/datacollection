import sys

t=input()
for i in range(1,t+1):
	a=(raw_input()).split()
	k,c,s=int(a[0]),int(a[1]),int(a[2])

	sys.stdout.write("Case #"+str(i)+": ",)

 	if c==1:
 		if s<k:
 			sys.stdout.write("IMPOSSIBLE")
 		else:
 			for j in range(1,s+1):
 				sys.stdout.write(str(j)+ " ")
 	else:
 		if s<(k+1)/2:
 			sys.stdout.write("IMPOSSIBLE")
 		else:
 			x=k**(c-1)
 			end=k*x
 			for j in xrange(0,k,2):
 				p=j*x+j+2
 				if p>end:
 					p=end
 				sys.stdout.write(str(p)+ " ")
 	print