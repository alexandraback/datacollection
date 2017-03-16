import sys
import math
import itertools

for testcase in xrange(1, int(sys.stdin.readline())+1):

  A, N = [int(w) for w in sys.stdin.readline().split()]

  sizes = [int(w) for w in sys.stdin.readline().split()]

  sizes.sort()
  num_steps = [0 for mote in xrange(N)]

  current_size = A
  cur_num_of_steps = 0
  current_mote = 0
  for value in sizes:
  	while current_size <= value and cur_num_of_steps < 100:
  		current_size += (current_size - 1)
  		cur_num_of_steps += 1
  	num_steps[current_mote] = cur_num_of_steps
  	current_size += value
  	current_mote += 1


  best = N
  current_mote = 1
  for num_steps_until_mote in num_steps:
  	option = num_steps_until_mote + N - current_mote
  	if option < best:
  		best = option
  	current_mote += 1

  print 'Case #%d: %d' % (testcase, best)