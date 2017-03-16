import sys, math

from collections import Counter

inp = open("in.txt")
out = open("out.txt","w+")
sys.stdout = out
tc = 0

class ImpossibleError(Exception):
	pass

t = int(inp.readline())

def print_case(case, result):
    debug("Case #%d: %s" % (case, str(result)))
    print "Case #%d: %s" % (case, str(result))

def debug(message):
	if len(sys.argv) > 1 and sys.argv[1] == "silent":
		return
	sys.stdout = sys.__stdout__
	print message
	sys.stdout = out

alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"

def take_max(parties):
    m = max(parties, key=lambda x: x[0])
    m[0] -= 1
    if m[0] == 0:
        parties.remove(m)
    return m[1]

debug(t)


for tc in xrange(t):
    j, p, s, k = [int(x) for x in inp.readline().split()]
    
    outfits = []
    c = Counter()
    for si in xrange(s):
        for pi in xrange(p):
            for ji in xrange(j):
                pair1 = "j%dp%d" % (ji, pi)
                pair2 = "j%ds%d" % (ji, si)
                pair3 = "p%ds%d" % (pi, si)
                if c[pair1] == k or c[pair2] == k or c[pair3] == k:
                    continue
                c[pair1] += 1
                c[pair2] += 1
                c[pair3] += 1
                outfits.append((ji+1, pi+1, si+1))
    
    r = "%d\n%s" % (len(outfits), "\n".join([" ".join([str(i) for i in outfit]) for outfit in outfits]))
    print_case(tc+1, r)