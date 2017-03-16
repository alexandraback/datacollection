def f(x):
	if (x == 0):
		return "INSOMNIA"
	digits = [0] * 10
	current = x
	while True:
		for c in str(current):
			digits[int(c)] = 1
		if (sum(digits)) == 10:
			return current
		current += x

n = int(input())
for i in range(n):
	x = f(int(input()))
	print("Case #{0}: {1}".format(i+1, x))
