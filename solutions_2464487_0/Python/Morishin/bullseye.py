def judge(n):
	y = 2*n*n + (2*r - 1)*n
	return y>t

fi = open('input.txt','r')
t = int(fi.readline())
for i in range(0,t):
	r,t = map(int,fi.readline().split())

	k = 1
	while 1 :
		if judge(k):
			break
		k = k+1
	print "Case #{0}: {1}".format(i+1,k-1)
fi.close