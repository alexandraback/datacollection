'''
Created on 12/apr/2014

@author: mlarocca
'''
from sys import argv

INITIAL_PRODUCTION = 2.0

def read_input(f):
  lines = open(f, 'r')
  n = int(lines.readline().strip())
  for i in xrange(n):
    c, f, x = map(float, lines.readline().strip().split(" "))
    
    yield i+1, c, f, x  

def compute(c, f, x):
  pps = INITIAL_PRODUCTION  #production per second

  t = 0.0
  old_total_time = float('inf')
  while True:
    time_to_farm = c / pps
    time_to_goal = x / pps
    if t + time_to_goal > old_total_time:
      return old_total_time
    else:
      old_total_time = t + time_to_goal
    
    #print t, time_to_farm, pps, old_total_time
    t += time_to_farm
    pps += f     
   
    
  
if __name__ == '__main__':
  for test_case, c, f, x in read_input(argv[1]):
    print "Case #%d: %.7f" % (test_case, compute(c,f,x))
