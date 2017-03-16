def gcd(n1, n2):
	n, rem = n1, n2 % n1
	while rem != 0:
		n, rem = rem, n % rem
	return n

def main():
	for TEST in xrange(1, int(raw_input())+1):
		P, Q = map(int, raw_input().split('/'))

		div = gcd(P, Q)
		P /= div
		Q /= div

		# print "%d/%d" % (P,Q)

		if bin(Q).count('1') == 1:
			shift = 0
			while (Q >> shift) > P:
				shift += 1
			print "Case #%d: %d" % (TEST, shift)
		else:
			print "Case #%d: %s" % (TEST, "impossible")
main()
