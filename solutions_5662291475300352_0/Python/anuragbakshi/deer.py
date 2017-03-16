import sys

input_file = open(sys.argv[1])
output_file = open(sys.argv[1] + ".out", "w")

def time_laps(h, n):
	return (n - h[0]) / h[1]

T = int(input_file.readline().strip())
for t in range(1, T + 1):
	N = int(input_file.readline().strip())

	hikers = []
	for i in range(N):
		D, H, M = tuple(map(int, input_file.readline().strip().split(" ")))
		for h in range(H):
			hikers.append((D / 360, 1 / (M + h)))

	s, f = sorted(hikers, key=lambda x: x[1])

	print(s, f)

	enc = 0
	if len(hikers) <= 1:
		enc = 0
	else:
		if time_laps(s, 1) < time_laps(f, 2):
			enc = 0
		else:
			enc = 1

	output_file.write("Case #{0}: {1}\n".format(t, enc))
