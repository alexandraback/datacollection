import sys
import os


def can(mid, r, d):

	m = mid + mid - 1
	pint = mid * 2 * r + (m * (m+1))/2

	return pint <= d

if __name__ == "__main__" :

	casos = int(sys.stdin.readline())
	for t in range(1, casos+1) :
		line = sys.stdin.readline()
		val = line.strip()
		r = int(val.split()[0])
		d = int(val.split()[1])

		left = 0; right = 2**63
		while left < right-1 :
			mid = (left + right) / 2
			if( can(mid, r, d) ) : left = mid
			else : right = mid

		print "Case #" + str(t) + ": %d" % left
