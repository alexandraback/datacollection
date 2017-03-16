import sys

T = int(sys.stdin.readline().strip())

for t in range(T):
	S = sys.stdin.readline().strip()
	l = S[0]
	for s in S[1:]:
		if s > l[0] or s == l[0]:
			l = s + l
		else:
			l = l + s
	print "Case #%d: %s"%(t+1, l)