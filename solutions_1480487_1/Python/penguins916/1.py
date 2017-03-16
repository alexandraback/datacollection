import math
from math import log
import numpy
import numpy.linalg

f = open('input.txt')
samples = int(f.readline().strip())
output = ''
for k in range(samples):
	print k, "on"
	line = [int (x) for x in f.readline().split(" ")]
	n = line[0]

	matrix= numpy.matrix(numpy.zeros([n,n], dtype=numpy.float64))
	solution = numpy.matrix(numpy.ones([n,1], dtype=numpy.float64))
	total = float(sum(line[1:]))
	vals = line[1:]
	#vals.sort()
	vals = sorted(zip(vals, range(len(vals))), key = lambda x: x[0])


	print vals
	min2 = vals[0]+vals[1]

	for h in range(1,n):
		mountNeeded=0
		for t in range(0,h):
			#print t, h
			mountNeeded += (vals[h][0]-vals[t][0])/total
		if mountNeeded > 1:
			n-=n-h
			break

	#put them back

	for h in range(n-1):
		matrix[h,h] = total
		matrix[h,h+1] = -total
		solution[h] = (-vals[h][0]+vals[h+1][0])
		matrix[n-1,h] = 1
	matrix[n-1,n-1] = 1
	#print matrix
	#print solution
	s = numpy.linalg.pinv(matrix)*solution*100

	out = [0 for x in range(len(vals))]

	#for k in range(len(vals)):
	#	out[vals[k][1]] = vals[k][0]

	#print s
	for x in range(s.shape[0]):
		out[vals[x][1]] = float(s[x])
	#print out
	#print s
	#print total
	output += 'Case #' + str(k+1)+':'
	for x in out:
		output += " "+'%.6f' % float(x)
	output+="\n"


o = open('output.txt', 'w')
o.write(output)
o.close
print output
