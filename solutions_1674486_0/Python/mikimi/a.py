from __future__ import division
import sys
import math
def read_input():
	'''
	Generates test-cases.
	'''	
	num_testcases = int(sys.stdin.readline())
	for _ in xrange(num_testcases):
		N = int(sys.stdin.readline())
		v = []
		for i in xrange(N):
			line = map(lambda x: int(x)-1, sys.stdin.readline().split())
			v.append(line[1:])
		yield (N, v)#N, s0...sN-1

def main((N, v)):
	#print "[main]: N, v", N, v
	
	#for each ind:
	for ind in xrange(N):
		#print "[main]: source ind:", ind
		#check if there are 2 paths from it:
		visited = set()
		from_nodes = [ind]
		while(len(from_nodes)>0):
			ind = from_nodes[0]
			from_nodes = from_nodes[1:]
			#print "[main]: ind, from_nodes, v[ind], visited:", ind, from_nodes, v[ind], visited
			
			for neigh in v[ind]:
				if neigh in visited:
					return "Yes"
				visited.add(neigh)
				from_nodes.append(neigh)
	return "No"
			
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
			print "Case #"+str(ind+1)+": "+result
	


