import time
import math
import fractions
import numpy as np
from math import *
from fractions import *
from operator import itemgetter, attrgetter

start = time.time()

fname = "D-small-attempt0"

ifile = open(fname + '.in', 'r')
ofile = open(fname + '.out', 'w+')

def fractile(num_case, k, c, s):
	ofile.write("Case #%d: " % (num_case+1))
	for j in range(0, s):
		ofile.write("%d " % (j+1))
	ofile.write("\n")



############ main #############################	
with ifile:
	[num_case] = [int(x) for x in ifile.readline().split()] 

	for i in range(0, num_case):
		[k, c, s] = [int(x) for x in ifile.readline().split()]
		fractile(i, k, c, s)







end = time.time()
print(end - start)



