from collections import defaultdict
from operator import mul

def ans1(n,m,k):
	if(k<=1):
		return 1
	p,q = 0,1
	while(q<k):
		p+=4
		q+=p		
	return p

def ans2(n,m,k):
	if(k<=2):
		return k
	p,q = 2,2
	while(q<k):
		p+=4
		q+=p		
	return p

t = input()
for case in range(1,t+1):
	n,m,k = [int(x) for x in raw_input().split(" ")]
	#a = min(ans1(n,m,k),ans2(n,m,k),ans3(n,m,k))
	if(k>(n*m)-4):
		ans=(n+m)*2+k-4-(n*m)
	else:
		a = (k,ans1(n,m,k),ans2(n,m,k))
		ans = min(a)
	if(n<=2 or m<=2):
		ans = k
	print("Case #{}: {}".format(case, ans))
	
