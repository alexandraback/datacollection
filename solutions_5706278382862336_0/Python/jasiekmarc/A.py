def gcd(a, b):
	if b == 0:
		return a
	return gcd(b, a%b)

duzo = 2**40

def solve():
	u = input()
	a, b = u.split('/')
	a = int(a)
	b = int(b)
	d = gcd(a, b)
	a = a/d
	b = b/d
	if duzo % b != 0:
		return 'impossible'
	a *= duzo/b
	cand = duzo
	ret = 0
	while cand > a:
		ret += 1
		cand /= 2
	return ret


def main():
	t = int(input())
	for i in range(1, t+1):
		print('Case #{}: {}'.format(i, solve()))

if __name__ == '__main__':
	main()