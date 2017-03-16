#!/usr/bin/python

# C. 

import sys
import math


f = sys.stdin
T = int(f.readline())
R, N, M, K = [int(i) for i in f.readline().split()]

print "Case #1:"

for case in range(1, R+1) :
	arr = [int(i) for i in f.readline().split()]

	ret = '222'
	for i in range(2, 5+1):
		for j in range(2, 5+1):
			for k in range(2, 5+1):
				flag = True
				for e in arr:
					if e == 1 or e == i or e == j or e == k or e == i*j or e == i*k or e == j*k or e == i*j*k:
						pass
					else:
						flag = False
						
				if flag:
					ret = str(i) + str(j) + str(k)

	print ret
