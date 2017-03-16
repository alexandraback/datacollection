import sys

data = sys.stdin.readlines()
T = int(data[0])
for i in range(1, T+1):
    E, R, N = tuple(map(int, data[2*i-1].split()))
    v = map(int, data[2*i].split())
    #print E, R, N, v
    gain = [0] * (E+1)
    for j in range(N):
	#print gain
	newgain = [0] * (E+1)
	#newgain = gain[:]
	for olde in range(E+1):
	    for e in range(E+1):
		ne = max(0, olde - e)
		ediff = olde - ne
		newe = min(E, ne + R)
		newg = gain[olde] + v[j] * ediff
		newgain[newe] = max(newgain[newe], newg)
	gain = newgain
    #print gain
    g = max(gain)
    print "Case #%d: %d" % (i, g)
