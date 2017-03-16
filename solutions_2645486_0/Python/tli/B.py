import sys
import math
import numpy


T = int(sys.stdin.readline())
for i in range(T):
	x = sys.stdin.readline().split(" ")
	E = int(x[0])
	E_max = E
	R = int(x[1])
	N = int(x[2])
	VV = sys.stdin.readline().split(" ")
	V = map(int, VV)
	V_tot = 0
	j = 0
	optimal_i = -1

	while j < N:
		optimal_i = optimal_i + numpy.argmax(V[j: N]) + 1
		j_old = j
		for j in range(j_old, optimal_i):
			E_spend = max(E + R - E_max, 0)
			# print "Spend", E_spend, "on", j
			V_tot = V_tot + E_spend * V[j]
			E = E - E_spend + R

		V_tot = V_tot + E * V[optimal_i]
		# print "Spend", E, "on", optimal_i

		E = R
		j = optimal_i + 1

	print "Case #" + str(i+1) + ": "+str(V_tot)				
