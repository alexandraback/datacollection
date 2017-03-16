import sys
from fractions import Fraction
import math

num_cases = int(sys.stdin.readline().strip())

def doesnt_have_any(s, chars, stripchar):
	s = s.lstrip(stripchar)
	for c in chars:
		if c in s:
			return False
	return True
	
def get_poss(pairs, last, prev_occ):
	if not last:
		return pairs[:]
	return filter(lambda p: doesnt_have_any(p, prev_occ, last[-1]), pairs)
	
#def helper(depth, pairs, last, prev_occ, used):
def helper(pairs, last, prev_occ):
	#print "depth %s, used %s - prev occ = %s" % (depth, used, prev_occ)
	if not pairs:
		#print "got one!"
		return 1
	poss = get_poss(pairs, last, prev_occ)
	#print "for %s, this is possible next: %s" % (last, poss)
	if not poss:
		return 0
	total = 0
	for p in poss:
		pairs.remove(p)
		missing_prevs = set(p) - prev_occ
		prev_occ |= missing_prevs
		#used.append(p)
		#res = helper(depth + 1, pairs, p[-1], prev_occ, used)
		res = helper(pairs, p[-1], prev_occ)
		#used.remove(p)
		prev_occ -= missing_prevs
		#print "res of %s, last %s is %s, used %s" % (pairs, p[-1], res, used)
		total += res
		pairs.append(p)
	# print "result of %s, last = %s is %s" % (pairs, last, total)
	return total
		

def solve(pairs):
	#return helper(0, pairs, '', set(), list())
	return helper(pairs, '', set())
	
for i in range(num_cases):
	num_pairs = int(sys.stdin.readline().strip())
	pairs = sys.stdin.readline().strip().split()
	#if i != 1: 
	#	continue
	result = solve(pairs)
	print "Case #%s: %s" % (i+1, result)
	
