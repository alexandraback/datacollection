import sys, math

def main(fin, fout):
	T = int(fin.readline())
	for t in range(T):
		X, R, C = map(int, fin.readline().strip().split())
		# print X, R, C

		# Sanity checks
		if (R*C) % X != 0:
			answer = 'RICHARD'
		elif X == 1 or X == 2:
			answer = 'GABRIEL'
		elif X == 3:
			if R*C == 3:
				answer = 'RICHARD'
			else:
				answer = 'GABRIEL'
		elif X == 4:
			if R * C == 16 or R * C == 12:
				answer = 'GABRIEL'
			else:
				answer = 'RICHARD'

		print "Case #%d: %s" % (t+1, answer)
		fout.write("Case #%d: %s\n" % (t+1, answer))

	return

if __name__ == '__main__':
	fin = open(sys.argv[1], "r")
	fout = open(sys.argv[2], "w")
	main(fin, fout)
