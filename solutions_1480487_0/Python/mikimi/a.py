from __future__ import division
import sys
import math
def read_input():
	'''
	Generates test-cases.
	'''	
	num_testcases = int(sys.stdin.readline())
	for _ in xrange(num_testcases):
		test_case = map(lambda x: int(x), sys.stdin.readline().split())
		yield (test_case[0], test_case[1:])#N, s0...sN-1

def main((N, points)):
	X = sum(points)
	if N==2:
		return [100*(points[1]+X-points[0])/(2*X), 100*(points[0]+X-points[1])/(2*X)]
	
	#N>=3 -> anyone can get 0%
	result = []
	ind = 0
	while ind < len(points):
		
		fun = lambda perc: is_percentage_enough(N, points, X, ind, perc)
		result.append(100*bin_search(fun))
		ind+=1
	return result
	
	
def is_percentage_enough(N, points, X, ind, perc):
	#checks if this perc is enough for ind not to be eliminated
	##print "[is_percentage_enough]: N, points, X, ind, perc", N, points, X, ind, perc
	ind_val = points[ind]+X*perc
	##print "[is_percentage_enough]: ind_val", ind_val
	
	used_perc = perc
	for neigh_ind in xrange(len(points)):
		if neigh_ind != ind:
			##print "for:", neigh_ind, "ind_val-points[neigh_ind])/X:", (ind_val-points[neigh_ind])/X
			used_perc += max( (ind_val-points[neigh_ind])/X, 0)
	
	if used_perc > 1:
		return True
	return False

def bin_search(fun):
	'''
	Find minimum True value to the 10^(-6) error rate.
	'''
	#print '[bin_search]: called'
	l_side = 0
	r_side = 1
	
	while True:
		if (abs((r_side - l_side)/r_side) < pow(10, -7)) or abs((r_side - l_side)) < pow(10, -7):
			#print '[bin_search]: returning'
			return (r_side+l_side)/2
			
		x = (l_side + r_side)/2
		#print '[bin_search]: x, l_side, r_side:', x, l_side, r_side
		
		if fun(x) == True:
			r_side = x
		else:
			l_side = x
			
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
			print "Case #"+str(ind+1)+": "+' '.join([str(r) for r in result])
	


