def judge(n):
	y = 2*n*n + (2*r - 1)*n
	return y<=t

def rec(a,b,cnt):
	if(cnt>100):
		rng = []
		rng.append(a)
		rng.append(b)
		return rng
	ave = a+int((b-a)/2)
	if judge(ave):
		return rec(ave,b,cnt+1)
	else:
		return rec(a,ave,cnt+1)

fi = open('input.txt','r')
t = int(fi.readline())
for i in range(0,t):
	r,t = map(int,fi.readline().split())

	ls = rec(1,10**9,0)
	k = min(ls)
	while 1:
		if judge(k)==False:
			break
		k=k+1

	print "Case #{0}: {1}".format(i+1,k-1)
	
fi.close