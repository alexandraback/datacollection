from __future__ import division
import sys
import math
from itertools import combinations

def read_input():
	'''
	Generates test-cases.
	'''	
	num_testcases = int(sys.stdin.readline())
	for _ in xrange(num_testcases):
		test_case = map(lambda x: int(x), sys.stdin.readline().split())
		yield (test_case[0], test_case[1:])

def main((N, S)):
	#print "[main]: (N, S)", N, S
	
	found_sums = {}
	for r in xrange(1, len(S)):
		for combination in combinations(S, r):
			sum_comb = sum(list(combination))
			#print "[main]: combination, sum_comb:", combination, sum_comb
			if sum_comb in found_sums:
				return [found_sums[sum_comb], list(combination)]
			else:
				found_sums[sum_comb] = list(combination)
	return ['Impossible']
	
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
		#print "ind:", ind, ind >= from_tc, ind <= to_tc
		if ind >= from_tc and ind <= to_tc:#this is the idea to divide testcases into a few parts
			result = main(test_case)
			#(points, C, D) = test_case
			#result = check_movable(points, C, D, 2.49)
			#print "result:", result
			print "Case #"+str(ind+1)+": "#+str(result)
			for res_line in result:
				if res_line!='Impossible':
					print ' '.join([str(x) for x in res_line])
				else:
					print 'Impossible'
	


