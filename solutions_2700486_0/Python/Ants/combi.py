import sys;

maxM = 255;

probs = [];
for i in xrange(maxM+2):
	probs.append([])
	for j in xrange(maxM+2):
		probs[i].append(0)

def prange(start,end):
	prod = long(1);
	for i in range(start,end+1):
		prod *= long(i);
	return prod;

def combis(n,k):
	if n-k < k:
		k = n-k;
	return prange(n+1-k,n)//prange(1,k);

for M in range(maxM+1):
	sum = long(0);
	for h in range(M,-1,-1):
		sum += combis(M,h);
		probs[M][h] = (1.0*sum) / (2**M);

print "double probs[",maxM+1,"][",maxM+2,"] = {"
for M in range(maxM+1):
	print "{",
	for h in range(maxM+2):
		sys.stdout.write(' {0:.16f}'.format(probs[M][h]));
		print ",",
	print "},"
print "}"