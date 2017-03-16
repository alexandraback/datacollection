import sys

def main():
	MAXN = 1000000;
	ar = [MAXN] * (MAXN + 1)
	ar[1] = 1
	ind = 1
	while ind <= MAXN:
		if ind + 1 <= MAXN:
			ar[ind + 1] = min(ar[ind + 1], ar[ind] + 1)
		x = int(str(ind)[::-1])
		if x <= MAXN:
			ar[x] = min(ar[x], ar[ind] + 1)
		ind += 1

	T = int(sys.stdin.readline())
	for i in range(T):
		n = int(sys.stdin.readline())
		print ('Case #' + str(i + 1) + ': ' + str(ar[n]))

if __name__ == '__main__':
	main()
