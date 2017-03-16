import fileinput
import math
def shifter(n):
	base = 10 ** (n-1)
	def shift(x):
		return (x % 10) * base + (x / 10)
	return shift

lines = fileinput.input()
lines.next()
for i,line in enumerate(lines):
	A,B = map(int, line.split())
	result = set()
	ndigits = len(str(A))
	shift = shifter(ndigits)
	for n in range(A,B+1):
		added = False
		shifts = set()
		for j in range(ndigits):
			shifts.add(n)
			n = shift(n)
		shifts = list(shifts)

		for (n1,n2) in [(n1,n2) for n1 in shifts for n2 in shifts if n1 != n2 and n1 >= A and n1 <= B and n2 >= A and n2 <= B]:
			result.add(tuple(sorted([n1,n2])))

	print "Case #%d:" % (i+1), len(result)
