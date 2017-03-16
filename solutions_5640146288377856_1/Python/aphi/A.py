from sys import stdin, stdout


def solve(R, C, W):

	total = 0

	total += R * (C / W) # search

	total += W # rest of ship incl miss

	if (C % W) == 0: # corner
		total -= 1 # no miss

	return total



if __name__ == '__main__':

	T = int(stdin.readline())

	for i in range(T):
		# read input for this problem

		R, C, W = map(int, stdin.readline().strip().split())
		result = solve(R, C, W)

		print "Case #%d: %s"%(i+1, result)