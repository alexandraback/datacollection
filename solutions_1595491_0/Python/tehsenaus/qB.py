
from jammly import Jam as BaseJam
import math

TEST = \
"""4
3 1 5 15 13 11
3 0 8 23 22 21
2 1 1 8 0
6 2 8 29 20 8 18 18 21"""

def md(a,b,c):
	return max(abs(a-b),abs(b-c),abs(c-a))

TRIPLETS = [
	(i,j,k) for i in range(11) for j in range(11) for k in range(11)
	if md(i,j,k) < 2
]
STRIPLETS = [
	(i,j,k) for i in range(11) for j in range(11) for k in range(11)
	if md(i,j,k) == 2
]

STOT = {}
for i,j,k in STRIPLETS:
	STOT[i+j+k] = (i,j,k)

NSTOT = {}
for i,j,k in TRIPLETS:
	NSTOT[i+j+k] = (i,j,k)

SRESULT = {}
for i,j,k in STRIPLETS:
	SRESULT[(max(i,j,k),i+j+k)] = (i,j,k)

NSRESULT = {}
for i,j,k in TRIPLETS:
	NSRESULT[(max(i,j,k),i+j+k)] = (i,j,k)


class Jam(BaseJam):
	r"""
	>>> Jam().runTest(TEST)
	Case #1: 3
	Case #2: 2
	Case #3: 1
	Case #4: 3
	"""
	

	def jam(self, line):
		line = map(int,line.split(" "))
		N, S, p = line[0:3]
		ts = line[3:]

		def surpr(t):
			return any([
				(s,t) in SRESULT for s in range(p,11)
			])
		def nsurpr(t):
			return any([
				(s,t) in NSRESULT for s in range(p,11)
			])
		def surp(t):
			return t in STOT
		def nsurp(t):
			return t in NSTOT
		
		srs = map(surpr, ts)
		nsrs = map(nsurpr, ts)
		ss = map(surp, ts)
		nss = map(nsurp, ts)

		# results which cannot be surprising
		numNSR = sum([(1 if not srs[i] and nsrs[i] and not ss[i] else 0) for i in range(N)])
		
		# results which may be surprising, but
		# are only results if not surprising
		numRns = sum([(1 if not srs[i] and nsrs[i] and ss[i] else 0) for i in range(N)])
		
		# non-results which can be surprising
		numNR = sum([(1 if not srs[i] and not nsrs[i] and ss[i] and nss[i] else 0) for i in range(N)])

		# results which may be surprising
		numR = sum([(1 if srs[i] and nsrs[i] else 0) for i in range(N)])

		# results which are only results if surprising
		numRs = sum([(1 if srs[i] and not nsrs[i] and ss[i] else 0) for i in range(N)])

		# results which must be surprising
		numSR = sum([(1 if srs[i] and not nsrs[i] and not ss[i] and not nss[i] else 0) for i in range(N)])

		# non-results which must be surprising
		numS = sum([(1 if not srs[i] and not nsrs[i] and ss[i] and not nss[i] else 0) for i in range(N)])
		
		
		
		numNR = sum([(1 if not srs[i] and not nsrs[i] else 0) for i in range(N)])

		#print S, p
		#print numNSR, numRns, numR, numRs, numSR, numS

		# use up desirable surprisings
		S -= numS + numSR + numRs

		if S < 0:
			# not enough, trim back the optionals
			numRs += S
		elif S > 0:
			# more to go, use up optionals
			#print S, numNR, numR, numRns
			S -= numR + numNR
			if S > 0:
				# still not enough, cut our results
				numRns -= S
		
		#print numNSR, numRns, numR, numRs, numSR, numS

		return numNSR + numRns + numR + numRs
	


if __name__ == "__main__":
	Jam.start()
