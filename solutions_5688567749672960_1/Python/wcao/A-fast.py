import sys

def solve(n):
	if n <= 10:
		return n
	add = 0
	if ((n % 10) == 0):
		add = 1
		n -= 1
	dig = len(str(n))
	left = 10 ** ((dig / 2) - 1)
	right = 10 ** (dig - (dig / 2))
	no_swap_max = (left + 1) * right - 1
	if n <= no_swap_max:
		return (n - (10 ** (dig - 1))) + add + solve(10 ** (dig - 1))

	add += (n % right)
	return add + solve(int(str(n)[:(dig/2)][::-1]) + (10 ** (dig - 1)))

def main():
	T = int(sys.stdin.readline())
	for i in range(T):
		n = int(sys.stdin.readline())
		print ('Case #' + str(i + 1) + ': ' + str(solve(n)))

if __name__ == '__main__':
	main()
