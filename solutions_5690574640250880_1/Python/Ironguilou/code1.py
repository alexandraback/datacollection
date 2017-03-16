
import sys
from numpy import *

#fileName = "vest"
fileName = "C-large"

fin = open(fileName + ".in")
fout = open(fileName + ".out", 'w')

NCases = int(fin.readline())
sys.stderr.write("NCases = " + str(NCases) + "\n")

def isPossible(R, C, M) :
	minRC = min(R, C)
	if minRC == 1 :
		return M <= R * C - 1
	elif minRC == 2 :
		return M % 2 == 0 and M <= R * C - 4 or M == R*C -1
	else :
		D = M - (R * C - 9)
		return D <= 0 or D in [1, 3, 5, 8]

for nline in range(0, NCases) :
	print "\n############################"
	print "# Case " + str(nline)
	
	R, C, M = map(int, fin.readline().strip().split())
	possible = isPossible(R, C, M)
	print R, C, M, possible
	
	if R > C :
		R, C = C, R
		transp = True
	else :
		transp = False
		
	sol = empty((R, C), dtype = str)
	bomb = '*'
	nobomb = '.'
	sol.fill(nobomb)
	sol[-1, -1] = 'c'
	if R == 1 :
		sol[0, 0:M] = bomb
	elif R == 2 :
		if M == R*C - 1 :
			sol[0,:] = bomb
			sol[1,:-1] = bomb
		else :
			sol[:, 0:(M/2)] = bomb
	else : # R >= 3
		D = M
		if D <= (R-3)*C :
			d, r = divmod(D, C)
			sol[0:d,:] = bomb
			sol[d,0:r] = bomb
			if r == C - 1 :
				sol[d,-2] = nobomb
				sol[d+1,0] = bomb
		else :
			sol[0:R-3,:] = bomb
			D -= (R-3)*C
			if D <= 3*(C-3) :
				d, r = divmod(D, 3)
				sol[R-3:,:d] = bomb
				if r == 1 :
					sol[R-3,d] = bomb
				elif r == 2 :
					sol[R-3,d:d+2] = bomb
			else :
				D = M - (R*C - 9)
				sol[R-3:,:C-3] = bomb
				print "D=",D
				if D == 1 :
					sol[-3,-3] = bomb
				elif D == 3 :
					sol[-3:,-3] = bomb
				elif D == 5 :
					sol[-3:,-3] = bomb
					sol[-3,-2:] = bomb
				elif D == 8 :
					sol[-3:,-3:-1] = bomb
					sol[-3:-1,-1] = bomb
				
	if transp :
		sol = sol.transpose()
	
	if sum(sol == bomb) == M :
		print "OK"
	else :
		print "ERROR"
	
	print R, C, M
	print sol
	
	fout.write("Case #" + str(nline+1) + ":\n")
	if possible :
		for i in range(sol.shape[0]) :
			fout.write("".join(sol[i,:]) + "\n")
	else :
		fout.write("Impossible\n")
	

fin.close()
fout.close()