import time
import math
import fractions
import numpy as np
from math import *
from fractions import *
from operator import itemgetter, attrgetter

start = time.time()

fname = "C-large"

ifile = open(fname + '.in', 'r')
ofile = open(fname + '.out', 'w+')

def prime(x):
	for i in range(2, int(sqrt(x))):
		if x%i == 0:
			return i
	if i == x-1:
		return 1

def base_transfer(base, array):
	v = 0
	for i in range(0, len(array)):
		v += (int(array[i]) * (base**(len(array)-1-i)))
	return v


##################### WATCH THIS ##########################
# one can prove that, for any base "b", a string of "0/1" satisfy the requirement
# as long as the middle 30 bits of it is divisible by "b+1", which is "11" in the representation


def jamcoin(num_case, n, j):
	ofile.write("Case #%d:\n" % (num_case+1))
	cnt = 0
	for b in range(1, n/2): # 225
		for a in range(0, n-3-2*b+2):
			ofile.write("1" + "0"*a + "11"*b + "0"*(n-2-2*b-a) + "1 3 4 5 6 7 8 9 10 11\n")
			cnt += 1
	for b in range(2, n-4):
		for a in range(b+3, n-1):
			ofile.write("1" + "0"*(b-2) + "11" + "0"*(a-b-2) + "11" + "0"*(n-a-2) + "1 3 4 5 6 7 8 9 10 11\n")
			cnt += 1
			if cnt == 500:
				return 0
# now it already has more than 500 solutions, only


############ main #############################	
with ifile:
	[num_case] = [int(x) for x in ifile.readline().split()]
#	num_case = 1
	for i in range(0, num_case):
		[n, j] = [int(x) for x in ifile.readline().split()]
#		n = 32
#		j = 500
		jamcoin(i, n, j)





end = time.time()
print(end - start)



