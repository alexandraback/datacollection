
def brute():
	r,t = map(int,input().split())
	
	y = 0
	while t > 0:
		p = (r+1)**2 - r**2
		if t >= p:
			y += 1
		t -= p
		r += 2
	
	return y
	


def binary():
	r,t = map(int,input().split())
	
	f = lambda n: 2*n*(n+1) + n*(2*r-3)
	
	low = 1
	high = 10**100
	
	mid = (low+high)//2
	
	while mid > low:
		required = f(mid)
		
		if required > t:
			high = mid-1
		else:
			low = mid
		
		mid = (low+high+1)//2
		#print(low,mid,high)
		
	return mid
	
	
for t in range(1,int(input())+1):
	print ("Case #%d: %d" % (t, binary()))