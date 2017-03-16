def invite(smax, s):
	if len(s) <= 1: return 0
	inv = 0
	cur = 0
	for i in range(len(s)):
		if s[i] == '0': continue
		if cur < i:
			inv = max(inv, i-cur)
		cur += int(s[i])
	return inv
	
import sys
f = open(sys.argv[1])
out_fname = sys.argv[1][:-2] + "out"
out = open(out_fname,"w")
T = int(f.readline().strip())

for tc in range(1, T+1):
	line = f.readline().strip()
	a = line.split()
	print >>out, "Case #%d: %d"%(tc, invite(a[0],a[1]))