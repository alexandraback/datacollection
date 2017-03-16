def area(r):
	return r**2 - (r-1)**2

def case():
	r, paint = [int(i) for i in input().split()]

	r += 1

	count = 0

	while paint >= area(r):
		paint -= area(r)
		r += 2
		count += 1

	print(count)

for i in range(1, int(input())+1):
	print('Case #%i: ' % i, end='')
	case()