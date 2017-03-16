#!/usr/bin/env python
# -*- coding: utf-8 -*-

import bisect

source = ["11",       
		"22",
		"111",
		"121",
		"212",
		"1111",
		"11111",
		"11211",
		"111111",
		"1111111",
		"11111111",
		"111111111",]

palindromic = list()

def divide(n, m):
	comb = []
	if m == 0:
		if n == 0:
			return [[]]
		else:
			return []
	if m == 1:
		if n >= 0:
			return [[n]]
		else:
			return []
	if n < 0:
		return []
	for i in range(n/2 + 1):
		tmp = divide(n - 2*i, m - 2)
		if tmp == None:
			break
		for j in tmp:
			j.insert(0, i)
			j.append(i)
			comb.append(j)
	return comb

def make_table():
	palindromic.append(1)
	palindromic.append(4)
	palindromic.append(9)
	for num in source:
		size = len(num)
		zero_num = 50 - size
		gap = size - 1;
		for zero in range(zero_num+1):
			div = divide(zero, gap)
			for x in div:
				tmp_num = num[0]
				for y in range(gap):
					tmp_num = tmp_num + '0'*x[y] + num[y+1]
				square = int(tmp_num)**2 
				if( square <= 10e100 ):
					palindromic.append( square )
	palindromic.sort()

make_table()

cas_n = int(raw_input())

for i in range(1, cas_n+1):
	A, B = [int(x) for x in raw_input().split(' ')]
	print "Case #{}: {}".format(i, bisect.bisect_right(palindromic, B) - bisect.bisect_left(palindromic, A))

