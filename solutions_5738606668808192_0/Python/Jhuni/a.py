def ttok(a,k):
	r=0
	x=1
	while a > 0:
		r += a%2*x
		x*=k
		a//=2
	return r
def pr(b):
	for p in prime:
		if b%p == 0:
			return p
	return -1
def printCJ(a,n,j):
	x=0
	while True:
		if x == j:
			return
		t = 1
		l = []
		for i in range(2,11):
			b = ttok(a,i)
			c = pr(b)
			if c == -1 or c == b:
				t=0
				break
			l.append(c)
		if t == 1:
			x+=1
			print("%d %d %d %d %d %d %d %d %d %d" % (ttok(a,10),l[0],l[1],l[2],l[3],l[4],l[5],l[6],l[7],l[8]))

		a+=2

M = 10000000
e = [0]*M
prime = [2]
i = 3
while i < M+1:
	if e[i] == 0:
		prime.append(i)
		
		j = i*3
		while j < M+1:
			e[j] = 1
			j += i*2
	i += 2



T = int(input())
for TT in range(1,T+1):
	d = input().split()
	n = int(d[0])
	j = int(d[1])
	a = (1 << (n-1)) + 1
	print("Case #%d:" % TT)
	printCJ (a,n,j)
