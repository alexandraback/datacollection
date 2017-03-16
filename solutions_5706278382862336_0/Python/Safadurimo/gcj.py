import sys
import re
import fractions

# open input files or stdin
filename = "input.txt"
inputFromFile=False
if inputFromFile: inp = open(filename)
else: inp=sys.stdin

# Precomputation
def is_power2(num):

	'states if a number is a power of two'

	return num != 0 and ((num & (num - 1)) == 0)

# solving a testcase
def solveTestCase(p,q,count):
    gcd = fractions.gcd(p, q)
    if(gcd>1):
        p/=gcd
        q/=gcd
    if(p==1 and q==1): return count
    if(not is_power2(q) or count == 39): return "impossible"
    if(p>=q/2): return count+1
    return solveTestCase(p*2,q,count+1)

T=int(inp.readline())
for t in range(1,T+1):
    p,q =[int(x) for x in inp.readline().split("/")]
    #print p,q
    print "Case #%d: %s" % (t,solveTestCase(p,q,0))
