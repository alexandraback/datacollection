#from __future__ import division
import sys
import math
from itertools import combinations

def read_input():
	'''
	Generates test-cases.
	'''	
	num_testcases = int(sys.stdin.readline())
	for _ in xrange(num_testcases):
		N, M = map(lambda x: int(x), sys.stdin.readline().split())
		a = []
		#for i in xrange(N):
		line = map(lambda x: int(x), sys.stdin.readline().split())
		##print "line:", line
		for l in xrange((len(line)+1)/2):
			a.append([line[2*l], line[2*l+1]])
		b = []
		#for i in xrange(M):
		line = map(lambda x: int(x), sys.stdin.readline().split())
		##print "line:", line
		for l in xrange((len(line)+1)/2):
			b.append([line[2*l], line[2*l+1]])
				
		yield (N, M, a, b)

def rec_find_best(a, b, curr_fit):
	#print "[rec_find_best], a, b, curr_fit:", a, b, curr_fit
	
	if len(a)==0 or len(b)==0:
		return curr_fit
	
	curr_max = curr_fit
	
	for n in xrange(len(a)):#dla kazdego startowego dopasowania po stronie n
		#bez tego a:
		a_new = map(lambda x: list(x), a[n+1:])
		sub_res = rec_find_best(a_new, b, curr_fit)
		curr_max = max(curr_max, sub_res)
		
		#zmatchuj tego a:
		bonus = 0
		for m in xrange(len(b)):#czy ten do niego pasuje?
			if a[n][1]==b[m][1]:
				#print "Dla dopasowania n, m,  a[n], b[m]:", n, m, a[n], b[m]
				sub_bonus = min(a[n][0],b[m][0])
				a[n][0] -= sub_bonus
				bonus += sub_bonus 
				
				if b[m][0] > sub_bonus:
					b_new = map(lambda x: list(x), b[m:])
					b_new[0][0] -= sub_bonus
					a_new = map(lambda x: list(x), a[n+1:])
					sub_res = rec_find_best(a_new, b_new, curr_fit+bonus)
				else:
					b_new = map(lambda x: list(x), b[m+1:])
					a_new = map(lambda x: list(x), a[n+1:])
					sub_res = rec_find_best(a_new, b_new, curr_fit+bonus)
				
				curr_max = max(curr_max, sub_res)
				
				if a[n][0] == 0:
					break
				
	#print "[rec_find_best] RETURNING"
	return curr_max

def main((N, M, a, b)):
	#print "[main]: (N, M, a, b)", N, M, a, b
	
	return rec_find_best(a, b, 0)
	
if __name__ == "__main__":
	try:
		from_tc = int(sys.argv[1])
	except:
		from_tc = 0
	try:
		to_tc = int(sys.argv[2])
	except:
		to_tc = 9999999999
	for ind, test_case in enumerate(read_input()):
		##print "ind:", ind, ind >= from_tc, ind <= to_tc
		if ind >= from_tc and ind <= to_tc:#this is the idea to divide testcases into a few parts
			result = main(test_case)
			#(points, C, D) = test_case
			#result = check_movable(points, C, D, 2.49)
			##print "result:", result
			print "Case #"+str(ind+1)+": "+str(result)
	


