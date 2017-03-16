#!/usr/bin/python
# -*- coding: utf-8 -*-
#
#	CodeJam 2012: Round-1B
#	Author: Mahmoud Aladdin (Platter)
#

file_in = open("A.in", 'r')
file_out = open("A.out", "w")
# ======================================
filereadLine = lambda: file_in.readline().strip()
filereadInt = lambda: int(file_in.readline().strip())
filereadInts = lambda: map(int, file_in.readline().strip().split(' '))
# ======================================
import math
# ======================================

def adjust(out, J, N):
	newOut, X, newX, nN = [], sum(J), 0, 0
	for i, val in enumerate(out):
		if(val < 0): continue
		newX += J[i]
		nN += 1
	a = (X + newX) / float(nN)
	for i in xrange(N):
		if out[i] < 0:
			newOut.append(0.0)
		else:
			ans = (a - J[i]) / float(X)
			newOut.append(ans)
	return newOut
	

def main():
	T = filereadInt()
	for tt in xrange(1, T + 1):
		S = filereadInts()
		N, J = S[0], S[1:]
		X = sum(J)
		a = (2 * X) / float(N)
		print X, a
		out = []
		for i in xrange(N):
			ans = (a - J[i]) / float(X)
			out.append(ans)
		while sorted(out)[0] < 0: 
			out = adjust(out, J, N)
		file_out.write("Case #{}: ".format(tt))
		for i, ch in enumerate(out):
			if i != 0:
				file_out.write(' ')
			file_out.write(str(ch * 100))
		file_out.write("\n")
	
	file_out.close()
	return 0
if __name__ == '__main__':
	main()
