def countTo(N):
	n = 1
	count = 1

	while True:
		if n == N:
			return count

		def reverse(x):
			return int(''.join(str(x)[::-1]))

		if N > reverse(n) > n:
			n = reverse(n)
			count += 1
		else:
			n += 1
			count += 1

def main():
	from sys import stdin
	input = stdin.read().split('\n')
	T = int(input[0])

	for t in range(T):
		N = int(input[t + 1])

		print "Case #{0}: {1}".format(t + 1, countTo(N))

if __name__ == '__main__':
	main()
