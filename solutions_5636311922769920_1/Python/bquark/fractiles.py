import math

fi = open("D-large.in")
fo = open("D-large.out", "w")

line = next(fi)
T = int(line)
for t in range(T):
	line = next(fi)
	[K, C, S] = [int(x) for x in line.split(' ')]
	smin = (K + C - 1) // C
	y = ['IMPOSSIBLE']
	if S >= smin:
		y = []
		k = 0
		while k < K:
			yy = 0
			for c in range(C):
				yy += K**(C-c-1) * min(k, K-1)
				k += 1
			y.append(yy+1)

	fo.write("Case #" + str(t+1) + ": " + ' '.join([str(s) for s in y]) + "\n")

fi.close()
fo.close()
