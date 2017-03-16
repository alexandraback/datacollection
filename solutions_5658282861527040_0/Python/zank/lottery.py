def calculate(a, b, k):
	count = 0
	for value_a in range(0, a):
		for value_b in range(0, b):
			if value_a & value_b < k:
				count += 1
	return count

t = int(input())
for i in range(t):
	a, b, k = [int(x) for x in input().split(' ')]
	print('Case #%s: %s' % (i + 1, calculate(a, b, k)))