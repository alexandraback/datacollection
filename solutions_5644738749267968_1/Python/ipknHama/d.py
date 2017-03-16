import bisect
tn = input()
pn = 0
while tn:
	tn -= 1
	pn += 1
	print 'Case #%d:'%pn,
	N = input()
	A = [float(x) for x in raw_input().split()]
	B = [float(x) for x in raw_input().split()]
	A.sort()
	B.sort()
	C = A[:]
	D = B[:]
	a = 0
	b = 0
	while A:
		if A[0] > B[0]:
			A.pop(0)
			B.pop(0)
			a += 1
		else:
			A.pop(0)
			B.pop()
	A,B=C,D
	while A:
		if A[-1] > B[-1]:
			A.pop()
			B.pop(0)
			b += 1
		else:
			x = A.pop()
			B.pop(bisect.bisect(B, x))

	print a,b

