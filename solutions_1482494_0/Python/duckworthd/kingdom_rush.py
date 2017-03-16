import sys

import Queue

def run(reqs):
  # run Djikstra's algorithm for a the implict graph given by states
  visited = set( [ ] )
  queue = Queue.PriorityQueue()
  queue.put( (0, initial_state(len(reqs))) )
  
  while not queue.empty():
    (val, state) = queue.get()
    
#    print 'Popped {} with value {}'.format(state, val)
    
    # check termination condition
    if sum(state) == 2*len(reqs):
      return val
    
    # build successors
    if state in visited:
      continue
    else:
      visited.add(state)
      for suc in  successor_states(state, reqs):
#        print 'Putting {} on queue with value {}'.format(suc, val+1)
        queue.put( (val+1, suc) )
        
  # failed to finish
  return 'Too Bad'

def initial_state(N):
  return tuple([0 for i in range(N)])

def successor_states(s, reqs):
  succ = []
  tot = sum(s)
  for (i, (a,b)) in enumerate(reqs):
    if s[i] == 0 and a <= tot:
      # can earn 1
      s_n = list(s)
      s_n[i] = 1
      succ.append( tuple(s_n) )
    if (s[i] == 0 or s[i] == 1) and b <= tot:
      # can earn 2
      s_n = list(s)
      s_n[i] = 2
      succ.append( tuple(s_n) )
  return succ


######
with open(sys.argv[1]) as f_in:
  with open(sys.argv[2], 'w') as f_out:
    f_in.readline()
    
    iter = 1
    while True:
      try:
        n_levels = int(f_in.readline())
        
        reqs = []
        for i in range(n_levels):
          l = f_in.readline().strip().split(" ")
          (a,b) = int(l[0]), int(l[1])
          reqs.append( (a,b) )
        
        res = "Case #{}: {}\n".format(iter, run(reqs))
        print res
        f_out.write(res)
      except Exception as e:
        print e
        break
      
      iter += 1