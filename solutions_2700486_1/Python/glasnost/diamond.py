import sys
import math
from decimal import Decimal

def hexag(i):
	return 2*(i**2)-i
	
def choose(n, k):
    if 0 <= k <= n:
        ntok = 1
        ktok = 1
        for t in xrange(1, min(k, n - k) + 1):
            ntok *= n
            ktok *= t
            n -= 1
        return ntok // ktok
    else:
        return 0

f = open(sys.argv[1], "r")
n = int(f.readline())
for i in range(1,n+1):
	sys.stdout.write("Case #" + repr(i) + ": ")
	n, xpos, ypos = [int(x) for x in f.readline().split()]
	xpos = abs(xpos)
	#sys.stdout.write(repr(n) + " " + repr(xpos) + " " + repr(ypos) + "\n")
	hexagn = [hexag(x)-n for x in range(1, 709)]
	minpos = 0
	prob = 0
	
	for i, x in enumerate(hexagn):
		if x > 0:
			minpos = i
			break
			
	#sys.stdout.write(repr(minpos) + " " + repr(hexag(minpos)-n) + " " + repr(hexag(minpos+1)-n) + " " + repr(ypos) + "\n")	
	
	if (minpos-1)*2 >= xpos + ypos:
		prob = 1
	elif (minpos+1)*2 <= xpos + ypos:
		prob = 0
	elif xpos == 0:
		prob = 0
	else:
		maxpos = abs(hexag(minpos)-n)
		for x in range(ypos+1, maxpos+1):
			prob = prob + choose(maxpos, x)
			#sys.stdout.write(repr(x) + " of " + repr(maxpos) + " must fall correctly: " + repr(choose(maxpos,x)) + " options\n")
			#sys.stdout.write(repr(ypos+1) + " of " + repr(maxpos) + ": " + repr(choose(ypos+1, maxpos)) + "\n")
			#sys.stdout.write(repr(prob) + " ")
		prob /= Decimal(2**maxpos)
		if hexag(minpos+1)-n <= (minpos*2)-ypos:
			#sys.stdout.write("overflow\n")
			prob = 1.0
	sys.stdout.write(str(prob) + "\n")