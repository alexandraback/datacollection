from random import randint
from fractions import gcd
def brent(N):
        if (N%2==0):
                return 2
        y,c,m = randint(1, N-1),randint(1, N-1),randint(1, N-1)
        g,r,q = 1,1,1
        while (g==1):             
                x = y
                for i in range(r):
                        y = ((y*y)%N+c)%N
                k = 0
                while (k<r and g==1):
                        ys = y
                        for i in range(min(m,r-k)):
                                y = ((y*y)%N+c)%N
                                q = q*(abs(x-y))%N
                        g = gcd(q,N)
                        k = k + m
                r = r*2
        if (g==N):
                while True:
                        ys = ((ys*ys)%N+c)%N
                        g = gcd(abs(x-ys),N)
                        if g>1:
                                break
         
        return g

def firstfac(n):
	i = 0
	x = 0
	while(i<3):
		x = brent(n)
		if(x!=n and x!=1):
			return x
		i = i + 1
	return n
	# i = 2
	# while((i*i)<=n):
	# 	if(n%i==0):
	# 		return i
	# 	i = i + 1
	# return n

n = 16
J = 50
print("Case #1:")
st = (1<<(n-1)) + 1
en = (1<<n)
cnt = 0
for i in range(st,en,2):
	s = bin(i)[2:]
	ar = []
	for b in range(2,11):
		num = int(s,b)
		fer = pow(2,num-1,num)
		if(fer==1):
			break
		fac = firstfac(num)
		if(fac==num):
			break
		ar.append(fac)
	if(len(ar)==9):
		print(s,end=' ')
		for j in range(9):
			print(ar[j],end=' ')
		print()
		cnt = cnt + 1
	if(cnt==J):
		break
