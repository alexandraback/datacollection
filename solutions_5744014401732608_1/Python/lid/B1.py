import sys
def main():
	t = int(raw_input())  # read a line with a single integer
	for i in xrange(1, t + 1):
		B, M = [int(s) for s in raw_input().split(" ")]
		out = [[0 for col in range(B)] for row in range(B)]
		outstr = "POSSIBLE"

		if M > maxRoutes(B):
			outstr = "IMPOSSIBLE"
		else:
			outstr = "POSSIBLE"


			for row in range(1,B):	# init all rows after 0 so elements above diag = 1
				for col in range(row+1, B):
					out[row][col] = 1

			if M == maxRoutes(B):
				out[0][B-1] = 1
				M -= 1
				

			colind = B-2
			while M > 0:
				if M % 2:
					out[0][colind] = 1
				M = M >> 1
				colind -= 1

		print "Case #{}: {}".format(i, outstr)
		if outstr == "POSSIBLE":
			for b in range(B):
				for b2 in range(B):
					# print str(out[b][b2]) + " ",
					sys.stdout.write(str(out[b][b2]))
				print ""
		sys.stdout.flush()

def maxRoutes(B):
	return 2 ** (B-2)

main()