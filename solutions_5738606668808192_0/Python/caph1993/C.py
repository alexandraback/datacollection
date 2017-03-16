import sys
from itertools import chain
sys.setrecursionlimit(1000000000)

in_file = "large"
in_file = "small"
#in_file = "sample"
sys.stdin = open(in_file+".in")
sys.stdout = open(in_file+".out","w")

def any_div(n):
	if n<NN: return divs[n]
	for p in primes:
		if n%p==0: return p
	return 0

NN = (1<<18)+10
primes = set()
divs = [0]*NN 
def sieve():
	isp = [1]*NN
	for i in range(2,NN):
		if isp[i]:
			for j in range(i*i,NN,i): isp[j]=0; divs[j]=i
			primes.add(i)
	return primes

def solve(N,J):
	x = 1+(1<<(N-1))
	ans = []
	while len(ans)<J and x<(1<<N):
		s = '{0:b}'.format(x)
		divg = (any_div(int(s,b)) for b in range(2,11))
		divl = [s]
		for d in divg:
			if d==0: break
			divl.append(d)
		#print(divl,len(divl))
		if len(divl)==10:
			ans.append(divl)
		x+=2
	return ans

ntc = int(input())
sieve()

for tc in range(ntc):
	N,J = map(int,input().strip().split(' '))
	ans = solve(N,J)
	print('Case #%d:'%(tc+1))
	for l in ans:
		print(" ".join(map(str,l)))
