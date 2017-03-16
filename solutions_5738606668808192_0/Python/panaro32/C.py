def parse():
	n, j = map(int, input().split())
	return n, j

def divisor(x):
	for i in range(2, int(x**0.5+1)):
		if not x%i: return i
	return 0

def solve(n, j):
	i = 0
	x = 2**(n-1)+1
	while i < j:
		s = bin(x)[2:]
		l = [divisor(int(s,b)) for b in range(2,11)]
		if all(l):
			print(s, end="")
			for d in l:
				print(" {}".format(d), end="")
			print("")
			i += 1
		x += 2

def main():
	for i in range(int(input())):
		n, j = parse()
		print("Case #{}:".format(i+1))
		k = solve(n, j)

if __name__ == "__main__": main()