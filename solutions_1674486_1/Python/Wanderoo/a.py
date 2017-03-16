# usage a.py <infile> > outfile
import sys

sys.setrecursionlimit(100000)

def check(i, inherits, found):
	if i in found:
		return True
	found.append(i)
	for j in inherits[i]:
		if check(j, inherits, found):
			return True
	return False

infile = sys.argv[1]

f = open(infile, "r")

T = (int) (f.readline().strip())

for t in range(1, T + 1):
	N = (int) (f.readline().strip())
	inherits = [[]]
	for n in range(1, N + 1):
		inherits.append(map(int, f.readline().split()[1:]))

	result = "No"
	for i in range(1, N + 1):
		if check(i, inherits, []):
			result = "Yes"
		
	print "Case #%d: %s" % (t, result)
	
f.close()
