
import sys
from numpy import *

#fileName = "test"
fileName = "D-small-attempt0"

fin = open(fileName + ".in")
fout = open(fileName + ".out", 'w')

NCases = int(fin.readline())
sys.stderr.write("NCases = " + str(NCases) + "\n")

def pointsRealWar(blocksN, blocksK) :
	iN = -1
	iK = -1
	z = 0
	while iK <= N - 2 and iN <= N - 2 :
		iN += 1
		iK += 1
		while iK < N and blocksN[iN] > blocksK[iK] :
			iK += 1
		
		if iK < N :
			z += 1
	return N - z

for nline in range(0, NCases) :
	print "\n############################"
	print "# Case " + str(nline)
	
	N = int(fin.readline().strip())
	blocksN = array(sorted(map(float, fin.readline().strip().split())))
	blocksK = array(sorted(map(float, fin.readline().strip().split())))
	
	# Real War
	z = pointsRealWar(blocksN, blocksK)	
	# Deceitful War
	y = N - pointsRealWar(-blocksN[::-1], -blocksK[::-1])
	
	fout.write("Case #" + str(nline+1) + ": %d %d\n" % (y, z))

fin.close()
fout.close()