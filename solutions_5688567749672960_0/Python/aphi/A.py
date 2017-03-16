from sys import stdin, stdout


def flip(n):
	return int(str(n)[::-1])

def solve(N):

	if N == 1:
		return 1

	reachable = set()
	prevReachable = set({1})
	everReachable = set({1})

	numbersSaid = 1

	while True:
		for r in prevReachable:
			if r+1 not in everReachable:
				reachable.add(r+1)

			flipped = flip(r)
			if flipped not in everReachable:
				reachable.add(flipped)

		numbersSaid += 1

		if N in reachable:
			return numbersSaid


		everReachable.update(reachable)
		prevReachable, reachable = reachable, set()


if __name__ == '__main__':

	T = int(stdin.readline())

	for i in range(T):
		# read input for this problem

		N = int(stdin.readline())
		result = solve(N)

		print "Case #%d: %s"%(i+1, result)