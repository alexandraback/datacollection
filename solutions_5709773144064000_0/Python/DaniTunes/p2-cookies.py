import sys

data = sys.stdin.readlines()
n = int(data[0])
for i in range(n):
    C, F, X = map(float, data[i+1].split())
    mintime = X / 2 + 1
    s = 0
    k = 0
    while True:
	t = 1/(2.0 + k*F)
	tot = C * s + X * t
	if tot < mintime:
	    mintime = tot
	else:
	    break
	s += t
	k += 1
    print "Case #%d:" % (i+1), mintime
