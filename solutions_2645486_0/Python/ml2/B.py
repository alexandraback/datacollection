import sys
import math
import itertools

range = lambda stop: iter(itertools.count().next, stop)

def get_possibilities(N, E):
	out_list = []
	for num in range(10**N):
		no_good = False
		num_str = str(num)
		num_str = num_str.zfill(N+1-len(num_str))
		first = True
		for char in list(num_str):
			if int(char) < E:
				no_good = True
				break
			elif first and int(char) < R:
				no_good = True
				break
			else:
				first = False
				continue
		if not no_good:
			out_list.append(num_str)
	return out_list

def next_text(current_test, N):
	return 1

for testcase in xrange(1, int(sys.stdin.readline())+1):
  E, R, N = [int(w) for w in sys.stdin.readline().split()]
  v = [int(w) for w in sys.stdin.readline().split()]

  max_matrix = [[] for i in xrange(N)]
  for j in xrange(E+1):
  	max_matrix[0].append(j*v[N-1])
  for from_last in xrange(1,N):
  	#print 'from_last: '+str(from_last)
 	for j in xrange(E+1):
 		#print 'j: '+str(j)
 		best_row = max_matrix[from_last-1]
 		#print best_row
 		min_poss = min(E, j+R)
 		#print min_poss
 		best = best_row[min_poss]
  		for use in xrange(1,j+1):
  			cur = v[N-1-from_last]*use + max_matrix[from_last-1][min(E, j-use+R)]
  			best = (max(cur,best))
  		max_matrix[from_last].append(best)

  #print max_matrix
  cur_best = max(max_matrix[N-1])
  print 'Case #%d: %d' % (testcase, cur_best)