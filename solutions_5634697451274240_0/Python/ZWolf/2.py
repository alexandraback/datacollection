import time
import math
import fractions
import numpy as np
from math import *
from fractions import *
from operator import itemgetter, attrgetter

start = time.time()

fname = "B-small-attempt0"


ifile = open(fname + '.in', 'r')
ofile = open(fname + '.out', 'w+')

def flip(num_case, array):
	l = len(array)
	status = 1
	cnt = 0
	for j in range(l-1, -1, -1):
		if status == 1 and array[j] == '-':
			status = -1
			cnt += 1
		elif status == -1 and array[j] == '+':
			status = 1
			cnt += 1

	print "Case #%d: %d" % (num_case+1, cnt)
	ofile.write("Case #%d: %d\n" % (num_case+1, cnt))



############ main #############################	
with ifile:
	[num_case] = [int(x) for x in ifile.readline().split()] 

	for i in range(0, num_case):
		[a] = [str(x) for x in ifile.readline().split()]
		b = list(a)
		flip(i, b)






end = time.time()
print(end - start)



