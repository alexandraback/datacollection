N = 10**6
A = [0]*(N+1)

def rev(n):
	return int(str(n)[::-1])

for i in range(1,N+1):
	A[i] = A[i-1]+1
	r = rev(i)
	if i%10!=0 and r<i:
		A[i] = min(A[i], A[r]+1)

for t in range(input()):
	print "Case #%s: %s"%(t+1, A[input()])
