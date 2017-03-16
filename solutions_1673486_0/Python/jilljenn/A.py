import operator

def fonction(A, B, p):
	prob = 1
	minKeystrokes = 2 * B - A + 2 * A + 2
	for l in range(A, -1, -1):
		if l < A:
			prob *= p[A - l - 1]
		nbKeystrokes = (B - A + 2 * l + 1) * prob + (2 * B - A + 2 * l + 2) * (1 - prob)
		if(nbKeystrokes < minKeystrokes):
			minKeystrokes = nbKeystrokes
	return min(minKeystrokes, B + 2)

if __name__ == '__main__':
	T = int(input())
	for t in range(T):
		args = [int(_) for _ in input().split()]
		A, B = args
		p = [float(_) for _ in input().split()]
		print("Case #{}: {}".format(t + 1, round(fonction(A, B, p), 6)))