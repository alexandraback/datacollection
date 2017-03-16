
import sys
from numpy import *

#fileName = "test"
fileName = "B-small-attempt0"

fin = open(fileName + ".in")
fout = open(fileName + ".out", 'w')

NCases = int(fin.readline())
sys.stderr.write("NCases = " + str(NCases) + "\n")

for nline in range(0, NCases) :
	print "\n############################"
	print "# Case " + str(nline)
	
	C, F, X = map(float, fin.readline().strip().split())
	nF = floor((F*X - 2*C - F*C) / (F*C)) + 1
	if nF < 0 :
		nF = 0
	t = C * sum(1.0 / (2.0 + arange(0, nF) * F)) + X / (2.0 + nF * F)
	print C, F, X, nF, t
	

	fout.write("Case #" + str(nline+1) + ": " + "%.10f" % t + "\n")

fin.close()
fout.close()