T = input()
N,J = map(int, input().split())

def tobase(n, base):
	r,p,b = 0,1,1
	while p < n:
		if n&p: r += b
		p <<= 1
		b *= base
	return r

print("Case #1:")
v = (1<<(N-1)) + 1
while J:
	divisor = {}
	for b in range(2,11):
		x = tobase(v, b)
		for d in range(2,50):
			if x%d == 0:
				divisor[b] = d
				break

	if len(divisor) == 9:
		print(tobase(v,10), end=' ')
		for b in range(2,11):
			print(divisor[b], end=' ')
		print()
		J -= 1
	v += 2
