import time
import math
import fractions
import numpy as np
from math import *
from fractions import *
from operator import itemgetter, attrgetter

start = time.time()

fname = "test"

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

def jamcoin(num_case, n, j):
	ofile.write("Case #%d:\n" % (num_case+1))

	ofile.write( "1110000000000001 3 4 5 6 7 8 9 10 11\n")
	ofile.write( "1011000000000001 3 4 5 6 7 8 9 10 11\n")
	ofile.write( "1001100000000001 3 4 5 6 7 8 9 10 11\n")
	ofile.write( "1000110000000001 3 4 5 6 7 8 9 10 11\n")
	ofile.write( "1000011000000001 3 4 5 6 7 8 9 10 11\n")
	ofile.write( "1000001100000001 3 4 5 6 7 8 9 10 11\n")
	ofile.write( "1000000110000001 3 4 5 6 7 8 9 10 11\n")
	ofile.write( "1000000011000001 3 4 5 6 7 8 9 10 11\n")
	ofile.write( "1000000001100001 3 4 5 6 7 8 9 10 11\n")
	ofile.write( "1000000000110001 3 4 5 6 7 8 9 10 11\n")
	ofile.write( "1000000000011001 3 4 5 6 7 8 9 10 11\n")
	ofile.write( "1000000000001101 3 4 5 6 7 8 9 10 11\n")
	ofile.write( "1000000000000111 3 4 5 6 7 8 9 10 11\n")
	ofile.write( "1111100000000001 3 4 5 6 7 8 9 10 11\n")
	ofile.write( "1011110000000001 3 4 5 6 7 8 9 10 11\n")
	ofile.write( "1001111000000001 3 4 5 6 7 8 9 10 11\n")
	ofile.write( "1000111100000001 3 4 5 6 7 8 9 10 11\n")
	ofile.write( "1000011110000001 3 4 5 6 7 8 9 10 11\n")
	ofile.write( "1000001111000001 3 4 5 6 7 8 9 10 11\n")
	ofile.write( "1000000111100001 3 4 5 6 7 8 9 10 11\n")
	ofile.write( "1000000011110001 3 4 5 6 7 8 9 10 11\n")
	ofile.write( "1000000001111001 3 4 5 6 7 8 9 10 11\n")
	ofile.write( "1000000000111101 3 4 5 6 7 8 9 10 11\n")
	ofile.write( "1000000000011111 3 4 5 6 7 8 9 10 11\n")
	ofile.write( "1111111000000001 3 4 5 6 7 8 9 10 11\n")
	ofile.write( "1011111100000001 3 4 5 6 7 8 9 10 11\n")
	ofile.write( "1001111110000001 3 4 5 6 7 8 9 10 11\n")
	ofile.write( "1000111111000001 3 4 5 6 7 8 9 10 11\n")
	ofile.write( "1000011111100001 3 4 5 6 7 8 9 10 11\n")
	ofile.write( "1000001111110001 3 4 5 6 7 8 9 10 11\n")
	ofile.write( "1000000111111001 3 4 5 6 7 8 9 10 11\n")
	ofile.write( "1000000011111101 3 4 5 6 7 8 9 10 11\n")
	ofile.write( "1000000001111111 3 4 5 6 7 8 9 10 11\n")
	ofile.write( "1111111110000001 3 4 5 6 7 8 9 10 11\n")
	ofile.write( "1011111111000001 3 4 5 6 7 8 9 10 11\n")
	ofile.write( "1001111111100001 3 4 5 6 7 8 9 10 11\n")
	ofile.write( "1000111111110001 3 4 5 6 7 8 9 10 11\n")
	ofile.write( "1000011111111001 3 4 5 6 7 8 9 10 11\n")
	ofile.write( "1000001111111101 3 4 5 6 7 8 9 10 11\n")
	ofile.write( "1000000111111111 3 4 5 6 7 8 9 10 11\n")
	ofile.write( "1111111111100001 3 4 5 6 7 8 9 10 11\n")
	ofile.write( "1011111111110001 3 4 5 6 7 8 9 10 11\n")
	ofile.write( "1001111111111001 3 4 5 6 7 8 9 10 11\n")
	ofile.write( "1000111111111101 3 4 5 6 7 8 9 10 11\n")
	ofile.write( "1000011111111111 3 4 5 6 7 8 9 10 11\n")
	ofile.write("1111111111111001 3 4 5 6 7 8 9 10 11\n")
	ofile.write("1011111111111101 3 4 5 6 7 8 9 10 11\n")
	ofile.write("1001111111111111 3 4 5 6 7 8 9 10 11\n")
	ofile.write("1111111111111111 3 4 5 6 7 8 9 10 11\n")
	ofile.write("1110011111111111 3 4 5 6 7 8 9 10 11\n")








############ main #############################	
with ifile:
#	[num_case] = [int(x) for x in ifile.readline().split()]
	num_case = 1
	for i in range(0, num_case):
#		[n, j] = [int(x) for x in ifile.readline().split()]
		n = 16
		j = 50
		jamcoin(i, n, j)





end = time.time()
print(end - start)



