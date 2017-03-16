def get_positions(K, C):

	num = 1;
	c = C-1
	i = 0
	positions = []
	while i < K:
		num += i * K**c
		c -= 1
		i += 1

		if c < 0 or i == K:
			positions.append(num)
			num = 1
			c = C-1

	return positions

if __name__ == "__main__":
	number_cases = int(input())
	for i in range(number_cases):
		K, C, S = [int(n) for n in input().split(" ")]
		print("Case #%s: " % (i+1), end="")

		if C*S < K:
			print("IMPOSSIBLE")
			continue

		print(" ".join([str(pos) for pos in get_positions(K, C)]))

