import math

def mult((s1,a), (s2,b)):
	s = s1 * s2
	if a == '1':
		return s, b
	if b == '1':
		return s, a
	if a == b:
		return s * -1, '1'
	if (ord(a)+1) % 3 == (ord(b) % 3):
		return s, chr(ord('i') + (ord(a)+2) % 3)
	return s * -1, chr(ord('i') + (ord(a)+1) % 3)

#print mult((1,'i'), (-1, 'j'))


def solve(L, X, string):
	acc = (1, '1')
	firstI = -1
	lastK = -1
	midJ = False
	# suffice to look at prefixes up to the first 4 copies of L
	for i in range(0, min(X,4) * L):
		acc = mult(acc, (1,string[i % L]))
		if acc == (1,'i') and firstI == -1:
			firstI = i
		# compute checksum of L^X, see if -1
		if i == L-1:
			s, val = acc
			midJ = (acc == (-1,'1') and X % 2 == 1) or (acc != '1' and X % 4 == 2)
		if i >= L-1 and firstI != -1:
			break

	acc = (1, '1')
	# suffice to look at 4 copies of L starting from the back
	for i in range(X*L-1, (X-min(X,4))*L-1, -1):
		acc = mult((1,string[i % L]), acc)    # not commutative
		if acc == (1,'k') and lastK == -1:
			lastK = i
			break

	if firstI != -1 and lastK != -1 and firstI < lastK+1 and midJ:
		return "YES"
	return "NO"

fin = open("C-small-attempt0.in", "r") 
lines = fin.readlines()

index = 0
T = int(lines[index])
index += 1

for i in range(0, T):
	L, X = [int(s) for s in lines[index].split()]
	string = lines[index+1]
	index += 2
	print "Case #" + str(i+1) + ": " + str(solve(L, X, string))
