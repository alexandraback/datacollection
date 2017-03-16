import math

def case():
	r, paint = [int(i) for i in input().split()]

	area = 0
	n = 0

	#while paint >= 2*n*(n-1) + n + 2*r*n:
	#	n += 1
	n = math.ceil((math.sqrt((2*r-1)**2+8*paint)-(2*r-1))/4) + 1

	while(paint < 2*n*(n-1) + n + 2*r*n):
		n -= 1

	print(n)

for i in range(1, int(input())+1):
	print('Case #%i: ' % i, end='')
	case()