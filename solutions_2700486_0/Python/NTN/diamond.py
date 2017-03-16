def getline():
	return [int(i) for i in input().split()]

def pyramid(diamonds):
	summa = 0
	height = 0
	while summa <= diamonds:
		height += 1
		summa += height

	summa -= height
	height -= 1

	if height % 2 == 0:
		summa -= height
		height -= 1

	return summa, height

def rec(a, b, free, target, limit):
	if free == 0:
		if a >= target:
			return 1.0
		else:
			return 0.0

	if b == limit:
		return rec(a+1, b, free-1, target, limit)
	else:
		return (rec(a+1, b, free-1, target, limit) + rec(a, b+1, free-1, target, limit)) / 2

def case():
	n, x, y = getline()

	#print(n, x, y)

	static, h = pyramid(n)
	free = n - static

	if abs(x) <= h - y - 1:
		print(1.0)
		return

	if abs(x) > h - y + 1:
		print(0.0)
		return

	if y == h + 1:
		print(0.0)
		return

	print(rec(0, 0, free, y + 1, h+1))


for i in range(1, int(input())+1):
	print('Case #%i: ' % i, end='')
	case()