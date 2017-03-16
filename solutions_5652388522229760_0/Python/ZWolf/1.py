import time
import math
import fractions
import numpy as np
from math import *
from fractions import *
from operator import itemgetter, attrgetter

start = time.time()

fname = "A-small-attempt0"

ifile = open(fname + '.in', 'r')
ofile = open(fname + '.out', 'w+')

def count(num_case, num):
	track = [0] * 10
	tmp = num
	cnt = 1
	if num == 0:
		print "Case #%d: INSOMNIA" % (num_case+1)
		ofile.write("Case #%d: INSOMNIA\n" % (num_case+1))
	else:
		while (track !=[1] * 10):
			tmp = num * cnt
			array = [int(x) for x in str(tmp)]
			for j in range(0, len(array)):
				if array[j] == 0:
					track[0] = 1
				elif array[j] == 1:
					track[1] = 1
				elif array[j] == 2:
					track[2] = 1
				elif array[j] == 3:
					track[3] = 1
				elif array[j] == 4:
					track[4] = 1
				elif array[j] == 5:
					track[5] = 1
				elif array[j] == 6:
					track[6] = 1
				elif array[j] == 7:
					track[7] = 1
				elif array[j] == 8:
					track[8] = 1
				elif array[j] == 9:
					track[9] = 1

			cnt += 1

		print "Case #%d: %d" % (num_case+1, tmp)
		ofile.write("Case #%d: %d\n" % (num_case+1, tmp))



############ main #############################	
with ifile:
	[num_case] = [int(x) for x in ifile.readline().split()] 

	for i in range(0, num_case):
		[num] = [int(x) for x in ifile.readline().split()]
		count(i, num)






end = time.time()
print(end - start)



