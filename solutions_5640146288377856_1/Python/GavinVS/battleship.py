def battleship(R, C, W):
	if R == 1:
		if W == 1:
			return C

		if W == C: # you cant miss
			return W
		if W * 2 > C: # you will miss exactly once
			return W + 1

		if C % W == 0:
			return W + C / W - 1
		else:
			return W + C / W
	else:
		return (R - 1) * C / W + battleship(1, C, W)

def main():
	from sys import stdin
	input = stdin.read().split('\n')
	T = int(input[0])

	for t in range(T):
		R, C, W = map(int, input[t + 1].split())

		print "Case #{0}: {1}".format(t + 1, battleship(R, C, W))

if __name__ == '__main__':
	main()