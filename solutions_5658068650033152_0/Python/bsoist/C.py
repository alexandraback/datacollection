import os, sys
from itertools import groupby
problem = sys.argv[0].split('.')[0]
try:
    fn = "%s-small-attempt%s.in" % (problem, sys.argv[1])
except:
    fn = "%s-large.in" % problem
lines = [line.strip() for line in open(fn)][::-1]
fout = open("%s.out" % problem,"w+")

for case in range(int(lines.pop())):
	N,M,K = map(int,lines.pop().split())
	rl = M-2
	stones = rl
	rows = (K-rl)/M
	stones += (rows*2)
	if K-stones >0:
		stones += min(K-stones,rows * rl)
	if stones > K or stones < 0:
		stones = K
	print >>fout, "Case #%s: %s" % ((case+1),stones)
