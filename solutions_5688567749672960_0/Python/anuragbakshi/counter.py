import sys

def flip(n):
	return int(str(n)[::-1])

input_file = open(sys.argv[1])
output_file = open(sys.argv[1] + ".out", "w")

T = int(input_file.readline().strip())
for t in range(1, T + 1):
	N = int(input_file.readline().strip())

	ops = 1
	n = 1

	if N <= 20:
		ops = N
	else:
		n = 11
		ops = 11

		while n != N:
			flipped = flip(n)
			flipped_next = flip(n + 1)

			# print(n, flipped, flipped_next)

			if (flipped > n + 1) and (flipped <= N) and ((flipped > flipped_next) or (flipped_next > N)):
				n = flipped
			else:
				n += 1

			ops += 1

	output_file.write("Case #{0}: {1}\n".format(t, ops))
