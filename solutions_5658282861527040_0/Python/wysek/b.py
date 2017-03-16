def solve():
	A, B, K = [int(x) for x in input().split()]
	result = 0
	for a in range(A):
		for b in range(B):
			if (a & b) < K:
				result += 1
	return result

def main():
	T = int(input())
	for t in range(1, T+1):
		r = solve()
		print("Case #%d: %s" % (t, r))

if __name__ == '__main__':
	main()

