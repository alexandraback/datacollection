for T in range(int(input())):
	n = int(input())
	A = list(map(float, input().split()))
	B = list(map(float, input().split()))
	A = sorted(A)
	B = sorted(B)
	c1 = c2 = 0
	i = j = 0
	while (i<n):
		if (A[i]>B[j]):
			i+=1
			j+=1
			c1+=1
		else:
			i+=1
	i = j = 0
	while (i<n):
		if (B[i]>A[j]):
			i+=1
			j+=1
			c2+=1
		else:
			i+=1

	print("Case #%d: %d %d"%(T+1,c1,n-c2))