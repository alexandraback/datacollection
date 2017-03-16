from pprint import pprint
import re
import string
import sys

def n_rotations_in_bounds(lower, upper):
  candidates = brute_force(lower, upper)
  #candidates = list(sorted(list(candidates)))
  #print 80*'-'
  #print 'all {} pairs:'.format(len(candidates))
  #pprint( candidates )
  return len(candidates)

def brute_force(lower, upper):
  candidates = set([])
  for i in xrange(lower, upper+1):
    # for every number in [lower, upper]
    str_i = str(i)
    for rot in xrange(len(str_i)):
      # for every rotation of that number's string
      str_j = str_i[rot:] + str_i[:rot]
      j = int(str_j)
      if lower <= j <= upper and i < j:
        # if both i,j \in [lower, upper] and i < j
        candidates.add( (i, j) )
  return candidates

with open(sys.argv[2], 'w') as f_out:
  with open(sys.argv[1]) as f_in:
    for (i, line) in enumerate(f_in):
      if i == 0:
        continue

      # parse input
      inputs = re.split('\s+', line.strip())
      (lower, upper) = [int(v) for v in inputs]

      # calculate output
      result = n_rotations_in_bounds(lower, upper)

      # write it
      f_out.write('Case #{}: {}\n'.format(i, result))
