from itertools import product

T = input()

def substitute(string, missing, integers):
	b_s = list(string)

	for i in xrange(len(missing)):
		b_s[missing[i]] = str(integers[i])
	#print b_s
	#print str(b_s)
	return "".join(b_s)

for qw in xrange(1, T + 1):
	print "Case #%d:" % qw,

	strings = raw_input().split(" ")
	C = strings[0]
	J = strings[1]

	mC = []
	mJ = []

	for i in xrange(len(C)):
		if C[i] == "?":
			mC.append(i)

	for i in xrange(len(J)):
		if J[i] == "?":
			mJ.append(i)

	minimum = float("inf")
	minA = C
	minB = J

	for i in product(range(10), repeat=len(mC)):
		for j in product(range(10), repeat=len(mJ)):
			a = substitute(C, mC, i)
			b = substitute(J, mJ, j)
			val = abs(int(a) - int(b))
			if val < minimum:
				minimum = val
				minA = a
				minB = b


	print minA, minB