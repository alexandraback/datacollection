def main():
	for TEST in xrange(1, int(raw_input())+1):
		size, N = map(int, raw_input().split())
		motes = map(int, raw_input().split())
		motes.sort()
		
		nOper = 0
		bestNOper = N

		if size > 1:
			for i in xrange(N):
				mote = motes[i]
				while size <= mote:
					size += size - 1
					nOper += 1
				size += mote

				if bestNOper >= nOper + (N-i-1):
					bestNOper = nOper + (N-i-1)
		
		print "Case #%d: %s" % (TEST, str(bestNOper))

main()
