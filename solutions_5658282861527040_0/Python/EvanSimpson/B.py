import itertools 
import operator

def hamdist(inp):
	"""Count the # of differences between equal length strings str1 and str2"""
	return sum(c1 != c2 for c1, c2 in itertools.izip(inp[0],inp[1]))
def dotproduct(v1, v2):
	"""Calculate dot product of v1 and v2"""
	return sum(imap(operator.mul, v1, v2))

def andVals(tup):
	return tup[0]& tup[1]

def values(a,b):
	return itertools.imap(andVals, itertools.product(a,b))

with open("B-small-attempt0.in", "r") as z:
	cases = int(z.readline().strip())
	output = ""
	for i in range(cases):
		A,B,K = z.readline().strip().split(" ")
		A = int(A)
		B = int(B)
		K = int(K)
		num = len([x for x in itertools.ifilter(lambda x: x< K, values(xrange(A),xrange(B)))])
		output+="Case #%s: %s\n" %((i+1), num)
	with open("B-small-attempt0.out", 'w') as o:
		o.write(output)
		