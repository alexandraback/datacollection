#!/usr/bin/env python
import sys

def main(argv=None):
	if argv is None:
		argv = sys.argv
	
	T = int(sys.stdin.readline())
	for t in xrange(T):
		N, M = map(int, sys.stdin.readline().split(" "))
		A = []
		for i in xrange(N):
			A.append(map(int, sys.stdin.readline().split(" ")))

		# Can only determine that the pattern is not possible.
		possible = True
		msg = "YES"

		# Trivial case.
		if N == 1 or M == 1:
			possible = True
		else:
			visited = [[False for j in xrange(M)] for i in range(N)]

			i = 0
			while i < N and possible:
				j = 0
				while j < M and possible:
					if not visited[i][j]:
						# If everything in this row has same or less height, OK.
						rowOK = True
						sameHeight = []
						for col in xrange(M):
							if A[i][col] > A[i][j]:
								rowOK = False
							elif A[i][col] == A[i][j]:
								sameHeight.append(col)
						# Everything of the same height dealt with.
						if rowOK:
							for col in sameHeight:
								visited[i][col] = True

						# If the row can't be cut using this height, try the column.
						sameHeight = []
						if not rowOK:
							for row in xrange(N):
								if A[row][j] > A[i][j]:
									possible = False
								elif A[row][j] == A[i][j]:
									sameHeight.append(row)
							# Everything of the same height dealt with.
							if possible:
								for row in sameHeight:
									visited[row][j] = True
					j += 1
				i += 1

		if not possible:
			msg = "NO"
		
		print "Case #%d: %s" % (t + 1, msg)

if __name__ == "__main__":
	sys.exit(main())

