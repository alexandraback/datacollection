def main():
	for TEST in xrange(1, int(raw_input())+1):
		A, B, K = map(int, raw_input().split())
		A, B = min(A, B), max(A, B)

		max_gen = A-1

		count = 0

		for a in xrange(A):
			for b in xrange(B):
				if a & b < K:
					count += 1

		print "Case #%d: %d" % (TEST, count)

main()
