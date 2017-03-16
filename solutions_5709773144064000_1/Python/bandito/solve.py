import sys



def solve(farm_cost, inc_farm_rate, goal):
  rate = 2.0
  clock = 0.0
  while(True): 
    A = goal / rate
    next_farm_cost = (farm_cost / rate)
    rate += inc_farm_rate
    B = goal / rate + next_farm_cost
    if (A < B):
      clock += A
      break
    clock += next_farm_cost
  return clock

if __name__ == '__main__':
  with open(sys.argv[1]) as f:
    cases = int(f.readline())
    for case_num in xrange(cases):
      farm_cost, inc_farm_rate, goal = map(float, f.readline().split())
      cost = solve(farm_cost, inc_farm_rate, goal)
      print 'Case #%d: %0.7f' %(case_num + 1, cost)

