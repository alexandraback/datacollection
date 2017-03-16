from sys import stdin, stdout

EPS = 1E-6

def solve(hikerGroups):
	hikers = []
	for hg in hikerGroups:
		degree, numHikers, revTime = hg

		for h in range(numHikers):
			hikers.append( (degree, (revTime + h) ) )

	if len(hikers) < 2:
		return 0

	hikers.sort(key=lambda i: (i[0], -i[1]), reverse=True) # further around, then fastest

	if len(hikers) > 2:
		raise RuntimeError

	
	# 2 hiker case only
	frontHikerTimeToReach0 = ((360 - hikers[0][0]) / 360.0) * hikers[0][1]
	frontHikerTimeToReach0Again = frontHikerTimeToReach0 + hikers[0][1]
	backHikerTimeToReach0 = ((360 - hikers[1][0]) / 360.0) * hikers[1][1]
	backHikerTimeToReach0Again = backHikerTimeToReach0 + hikers[1][1]


	if max(frontHikerTimeToReach0, backHikerTimeToReach0) < (min(frontHikerTimeToReach0Again, backHikerTimeToReach0Again) - EPS):
		return 0 # stay behind both

	return 1


if __name__ == '__main__':

	T = int(stdin.readline())

	for i in range(T):
		# read input for this problem

		N = int(stdin.readline())
		hikerGroups = []
		for _ in range(N):
			degree, numHikers, revTime = map(int, stdin.readline().strip().split())
			hikerGroups.append((degree, numHikers, revTime))

		# map(int, stdin.readline().strip().split())
		result = solve(hikerGroups)

		print "Case #%d: %s"%(i+1, result)