# -*- coding: utf-8 -*-
# <nbformat>3.0</nbformat>

# <codecell>

import sys
import math

# <codecell>
"""
def divisor(n):
    #returns the smallest divisor for n greater than 1
    if n % 2 == 0:
        return 2
    if n % 3 == 0:
        return 3
    
    d = 5
    w = 2
    while d*d <= n:
        if n % d == 0:
            return d
        d += w
        w = 6 - w
    
    return 0
        
    
def is_coin_jam(s):
    given a number given as a binary string, determine if it is a composite number in all bases from 2 to 10
    l = []
    for base in range(2,11):
        n = divisor(int(s,base))
        if n > 0:
            l.append(n)
        else:
            return []
    return l
"""
def find_all_splits(low, high, num_pairs, target):
	""" this should return a list of lists of indices of good numbers """
	ret = []
	if num_pairs == 0:
		return [[]]
	i = low
	while target > 0 and i < high-1:
		for l in find_all_splits(i+2, high, num_pairs-1, target):
			ret.append([i,i+1] + l)
			target -= 1
		i += 1
	return ret

def split_to_str_div(l,n):
	l.sort(reverse=True)
	s = "11"
	prev = n - 1
	for x in l:
		s += "0"*(prev - x - 1) +"1"
		prev = x
	s += "0"*(prev - 3) + "11"
	ret = [s]
	for i in range(2,11):
		ret.append(i+1)
	return ret

def find_all_numbers(n, num_non_zero, target):
	ret = []
	l = find_all_splits(3,n-1, num_non_zero, target)
	for x in l:
		ret.append(split_to_str_div(x,n))

	return ret

target = 500
found = 0
number = 0
num_non_zero = 1
n = 32
l = []
print "Case #1:"
while found < target:
	l += find_all_numbers(n, num_non_zero, target)
        found += len(l)
    	num_non_zero += 1

for i in range(target):
	ans = l[i]
	s = str(ans[0])
	for x in ans[1:]:
		s += " {0}".format(x)
	print s

#test = [30, 15,4]
#print split_to_str_div(test,n)

# <codecell>


