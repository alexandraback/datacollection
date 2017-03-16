import sys

def num_eat(cur_size, goal_size):
  count = 0
  while cur_size < goal_size:
    cur_size += cur_size - 1
    #print cur_size
    count += 1
  return count, cur_size

num_cases = int(raw_input())
for casenum in range(1, num_cases+1):
  mote_size, num_motes = [int(z) for z in raw_input().split()]
  motes = [int(z) for z in raw_input().split()]
  motes.sort()
  num_ops = 0
  min_ops = 1000
  num_removed = 0
  for mote_index in range(len(motes)):
    if mote_size > motes[mote_index]:
      mote_size += motes[mote_index]
    else:
      min_ops = min(min_ops, num_ops +  len(motes) - mote_index) #remove all remaining
      # add until bigger
      if mote_size == 1:
        break
      num_added, mote_size = num_eat(mote_size, motes[mote_index] + 1)
      mote_size += motes[mote_index]
      #print num_added
      #print mote_size
      num_ops += num_added
  
  if num_ops == 0 and min_ops == 1000:
    min_ops = 0
  elif num_ops > 0 and min_ops > 0:
    min_ops = min(min_ops, num_ops)
  
  print "Case #" + str(casenum) +  ": " + str(min_ops)
      
