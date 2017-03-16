I = lambda: map(int, input().split())
T=int(input())

def f(r,x,t):
	t-=(4*(r+x)-2)*x/2
	return t>=0

def main():
	r, t= I()
	L=0
	R=100000000000009
	
	while L<R-1:
		M=L+R>>1
		if f(r,M,t):
			L=M
		else:
		 	R=M
			
	print("Case #%d: %d"%(i+1,L))
	
for i in range(T):
	main()