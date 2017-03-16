#!/usr/bin/env python
# -*- coding: utf-8 -*-
import math

q = {
	("1", "1") : ["1", 1],
	("1", "i") : ["i", 1],
	("1", "j") : ["j", 1],
	("1", "k") : ["k", 1],
	("i", "i") : ["1", -1],
	("i", "j") : ["k", 1],
	("i", "k") : ["j", -1],
	("j", "j") : ["1", -1],
	("j", "k") : ["i", 1],
	("k", "k") : ["1", -1],
	("i", "1") : ["i", 1],
	("j", "1") : ["j", 1],
	("k", "1") : ["k", 1],
	("j", "i") : ["k", -1],
	("k", "i") : ["j", 1],
	("k", "j") : ["i", -1]
}

def quaternion(a, b, sign):
	return q[(a,b)][0], q[(a,b)][1] * sign

def find(letter, pattern):
	value = "1"
	sign = 1
	for i in range(len(pattern)):
		value, sign = quaternion(value, pattern[i], sign)
		if value == letter and sign == 1:
			return i
	return -1

def calc(pattern):
	value = "1"
	sign = 1
	for i in range(len(pattern)):
		value, sign = quaternion(value, pattern[i], sign)
	return value, sign

def solve(lx, s):
	l, x = map(int, lx.split())
	length = x * l

	i_string = s * 4
	index_i = find("i", i_string)
	if index_i == -1 or index_i > length - 3:
		return "NO"

	j_string = i_string[index_i+1:] + s*4
	index_j = find("j", j_string)
	if index_j == -1 or index_j + index_i > length - 3:
		return "NO"
	
	used = int(math.ceil((index_i + index_j + 2) * 1.0 / l))
	k_string = (used * s)[index_i+index_j+2:]
	
	x = (x - used) % 4
	k_string += x*s
	value, sign = calc(k_string)

	if value != "k" or sign != 1:
		return "NO"

	return "YES"



if __name__ == "__main__":
    testcases = input()
     
    for caseNr in xrange(1, testcases+1):
    	lx = raw_input()
        cipher = raw_input()
        print("Case #%i: %s" % (caseNr, solve(lx, cipher)))