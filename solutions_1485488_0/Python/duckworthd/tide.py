import re
import itertools
import sys
import os
import Queue

import ipdb

import numpy as np

def process(H,N,M, lowers, uppers):
  q = Queue.PriorityQueue()
  for pos in initial_states(H,N,M,lowers,uppers):
    q.put( (0, H, pos) ) # (time, water height, position in 2D)
  seen = set( [] )
  
  print 'initial states: {}'.format(initial_states(H,N,M,lowers,uppers))

  while not q.empty():
    (time, height, position) = q.get()
    print 'Popping {}'.format( (time, height, position) )
    
    if position == (N-1, M-1):
      return time
    
    if position in seen:
      continue
    else:
      seen.add( position )
    
#    print 'states after {}'.format( list(next_states(position, height, lowers, uppers)) )
    
    for (delta_t, new_pos) in next_states(position, height, lowers, uppers):
      assert delta_t > 0 
      new_time = time + delta_t
      new_height = max(height - delta_t*10, 0)
      q.put( (new_time, new_height, new_pos) )
      
def initial_states(H, N, M, lowers, uppers):
  seen = set( [] )
  def reachable(here):
    for (delta_i, delta_j) in [(-1, 0), (1, 0), (0,-1), (0,1)]:
      there = (here[0]+delta_i, here[1] + delta_j)
    
      if not (0 <= there[0] < lowers.shape[0] and 0 <= there[1] < lowers.shape[1]):
  #      print '{} out of bounds'.format(there)
        continue  # fallen off map
      low_there = lowers[there[0], there[1]]
      high_there = uppers[there[0], there[1]]
      low_here = lowers[here[0], here[1]]
      high_here = uppers[here[0], here[1]]
    
      if (there not in seen and 
          can_advance(low_here, high_here, low_there, high_there) and
          H <= high_there - 50):
        seen.add(there)
        yield( there )
        for other in reachable(there):
          yield other
  return [(0,0)] + list(reachable( (0,0) ))
    
def next_states(pos, height, lowers, uppers):
  res = []
  
  low_here = lowers[pos[0], pos[1]]
  high_here = uppers[pos[0], pos[1]]
  for (delta_i, delta_j) in [(-1, 0), (1, 0), (0,-1), (0,1)]:
    there = (pos[0]+delta_i, pos[1] + delta_j)
    
    if not (0 <= there[0] < lowers.shape[0] and 0 <= there[1] < lowers.shape[1]):
#      print '{} out of bounds'.format(there)
      continue  # fallen off map
    low_there = lowers[there[0], there[1]]
    high_there = uppers[there[0], there[1]]
    
    if can_advance(low_here, high_here, low_there, high_there):
      delta_t = time_to_advance(height, low_here, high_here, low_there, high_there)
      res.append( (delta_t, there) )
    else:
#      print 'cant advance to {}'.format(there)
      pass
  return res

def can_advance(low_here, high_here, low_there, high_there):
  # true if you can EVER advance
  return (low_there <= high_there - 50 and
      low_here  <= high_there - 50 and
      low_there <= high_here - 50)

def time_to_advance(height, low_here, high_here, low_there, high_there):
  # time until you can advance + time taken to advance
  if can_advance(low_here, high_here, low_there, high_there):
    
    # calculate time until water falls below necessary levels
    time_till_advance = (height - (high_there-50)) / 10.0
    if time_till_advance < 0:
      time_till_advance = 0.0
    
    # calculate time to move from here to there
    new_height = height - 10.0*time_till_advance
    if new_height - low_here >= 20:
      advance_time = 1.0
    else:
      advance_time = 10.0
    return time_till_advance + advance_time
  else:
    return np.nan

def parseints(line):
  return [int(v) for v in line.strip().split(" ")]

def main(path_in, path_out):
  with open(path_in) as f_in:
    with open(path_out, 'w') as f_out:
      n_examples = int(f_in.readline())
      for case in range(1, n_examples+1):
        # parse
        (H,N,M) = parseints(f_in.readline())
        lowers = []
        uppers = []
        for i in range(N):
          uppers.append(parseints(f_in.readline()))
        for i in range(N):
          lowers.append(parseints(f_in.readline()))
        lowers = np.array(lowers)
        uppers = np.array(uppers)
        
        # actual code logic
        print H
        print lowers
        print uppers
#        ipdb.set_trace()
        output = process(H,N,M,lowers, uppers)
      
        out_str = "Case #{}: {:.6f}\n".format(case, output)
        print out_str
        f_out.write(out_str)

if __name__ == '__main__':
  main(sys.argv[1], sys.argv[2])