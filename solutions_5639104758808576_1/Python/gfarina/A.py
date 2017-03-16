import sys

lines = sys.stdin.readlines()

T = int(lines[0])

for t in xrange(1, T + 1):
	Smax = int(lines[t].split()[0])
	ppl = map(int, list(lines[t].split()[1]))

	standup = 0
	ans = 0
	for s in xrange(Smax + 1):
		if standup < s:
			diff = s - standup
			standup += diff
			ans += diff
		standup += ppl[s]

	print "Case #%d: %d" % (t, ans)