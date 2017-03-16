from __future__ import division

def f(n, x, y):
	k = 0
	sum = 0
	while(True):
		sum = sum + k*4 + 1
		if sum > n:
			break
		k = k + 1
	sum = sum-k*4-1
	k = k-1

	print n,k,sum
	
	if x < 0 : x = -x
	
	if x+y <= k+k : return 1.0
	if n==sum : return 0.0
	if x+y > k+k+2 : return 0.0
	if x == 0 : return 0.0
	
	n = n - sum
	
	ps = [0] * (k+k+3)
	ps[0]=0.5
	ps[1]=0.5
	for m in range(2,n+1):
		nps = [0] * (k+k+3)
		for i in range(0,k+k+3):
			l = i
			r = m-1-l
			if r>k+k+2 : continue
			if r<0 : continue
			if l == k+k+2 : nps[l] = nps[l] + ps[l]
			elif r == k+k+2 : nps[l+1] = nps[l+1] + ps[l]
			else :
				nps[l] = nps[l] + ps[l]/2.0
				nps[l+1] = nps[l+1] + ps[l]/2.0
		ps = nps[0:k+k+3]
	
	print ps
	
	p = 0.0
	for l in range(0,k+k+3):
		r = n-l
		if r>k+k+2 : continue
		if r<0 : continue
		print l,r
		if l-1>=y : p = p + ps[l]
	
	return p

fin = open('d:\B-small-attempt0.in')
fout = open('d:\output.txt', 'w')

testcasen = [int(x) for x in fin.readline().split()][0]
print testcasen

for t in range(0,testcasen):
	fout.write('Case #'+str(t+1)+': ')
	n, x, y = [int(x) for x in fin.readline().split()]
	res = f(n,x,y)
	fout.write(str(res)+'\n')