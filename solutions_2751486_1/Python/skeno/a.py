# /usr/bin/python
import sys

def dbg(s): sys.stderr.write(str(s) +"\n")
def reads(t): return map(t, input().split(" "))
def readstrtolist(): return [x  for x in input()]
def read(t) : return t(input())


cc = frozenset(['a', 'e', 'i', 'o', 'u'])

T = read(int)

for t in range(1, T+1):
	[s, N] = reads(lambda x: x)
	N = int(N)
	
	cs = 0
	ngc = 0
	group = False
	size = len(s)
	nc = 0
	lcnc = 0
	for i in range(0, size):
		#~ dbg(s[i])
		if not s[i] in cc:
			if ngc < N:
				ngc += 1
			if ngc == N or group:
				lcnc = i+1-N + 1
				nc += lcnc
				if ngc == N:
					ngc = 0
					cs += 1
					group = True
				
			else:
				nc += lcnc
		else:
			group = False
			ngc = 0;
			nc += lcnc
		#~ dbg(nc)

	print("Case #%d: %d" % (t, nc))
