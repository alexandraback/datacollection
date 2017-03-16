def one_test():
	n = int(input())
	if n == 0:
		return 'INSOMNIA'
	seen = set()
	x = 0
	while len(seen) < 10:
		x += n
		seen |= set(str(x))
	return x

t = int(input())

for i in range(1, t + 1):
	print("Case #{}: {}".format(i, one_test()))
