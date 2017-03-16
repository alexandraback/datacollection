
def gcd(a, b):
	if b == 0:
		return a
	return gcd(b, a % b)

def case():
	a, b = input().split("/")
	a = int(a)
	b = int(b)

	div = gcd(b, a)
	a /= div
	b /= div

	for i in range(1,41):
		if b == 2**i:
			power = i
			break
	else:
		print("impossible")
		return

	for i in range(1,41):
		if 2 ** (power - i) <= a:
			print(i)
			return


for i in range(int(input())):
	print("Case #%i: " % (i+1), end="")
	case()