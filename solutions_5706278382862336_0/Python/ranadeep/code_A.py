from fractions import gcd

ans = "Case #{}: {}"

def f(a,b):
	g = gcd(a,b)
	a,b = a//g,b//g
	if(b&(b-1) != 0):
		return "impossible"
	k = 0
	while(a<b):
		b>>=1
		k+=1
	return k

def takeInp():
	for t in range(int(input())):
		a,b = map(int,input().split("/"))
		print(ans.format(t+1,f(a,b)))


takeInp()